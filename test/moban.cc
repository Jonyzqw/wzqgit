#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <time.h>
#include <chrono>
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h" // or "../stdout_sinks.h" if no color needed
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
 
static inline int NowDateToInt()
{
	time_t now;
	time(&now);
 
	// choose thread save version in each platform
	tm p;
#ifdef _WIN32
	localtime_s(&p, &now);
#else
	localtime_r(&now, &p);
#endif // _WIN32
	int now_date = (1900 + p.tm_year) * 10000 + (p.tm_mon + 1) * 100 + p.tm_mday;
	return now_date;
}
 
static inline int NowTimeToInt()
{
	time_t now;
	time(&now);
	// choose thread save version in each platform
	tm p;
#ifdef _WIN32
	localtime_s(&p, &now);
#else
	localtime_r(&now, &p);
#endif // _WIN32
 
	int now_int = p.tm_hour * 10000 + p.tm_min * 100 + p.tm_sec;
	return now_int;
}
 
class XLogger
{
public:
	static XLogger* getInstance()
	{
		static XLogger xlogger;
		return &xlogger;
	}
 
	std::shared_ptr<spdlog::logger> getLogger()
	{
		return m_logger;
	}
 
private:
	// make constructor private to avoid outside instance
	XLogger()
	{
		// hardcode log path
		const std::string log_dir = "./log"; // should create the folder if not exist
		const std::string logger_name_prefix = "test_";
 
		// decide print to console or log file
		bool console = false;
 
		// decide the log level
		std::string level = "debug";
 
		try
		{
			// logger name with timestamp
			int date = NowDateToInt();
			int time = NowTimeToInt();
			const std::string logger_name = logger_name_prefix + std::to_string(date) + "_" + std::to_string(time);
 
			if (console)
				m_logger = spdlog::stdout_color_st(logger_name); // single thread console output faster
			else
				//m_logger = spdlog::create_async<spdlog::sinks::basic_file_sink_mt>(logger_name, log_dir + "/" + logger_name + ".log"); // only one log file
				m_logger = spdlog::create_async<spdlog::sinks::rotating_file_sink_mt>(logger_name, log_dir + "/" + logger_name + ".log", 500 * 1024 * 1024, 1000); // multi part log files, with every part 500M, max 1000 files
 
			// custom format
			m_logger->set_pattern("%Y-%m-%d %H:%M:%S.%f <thread %t> [%l] [%@] %v"); // with timestamp, thread_id, filename and line number
 
                        if (level == "trace")
			{
				m_logger->set_level(spdlog::level::trace);
				m_logger->flush_on(spdlog::level::trace);
			}
			else if (level == "debug")
			{
				m_logger->set_level(spdlog::level::debug);
				m_logger->flush_on(spdlog::level::debug);
			}
			else if (level == "info")
			{
				m_logger->set_level(spdlog::level::info);
				m_logger->flush_on(spdlog::level::info);
			}
			else if (level == "warn")
			{
				m_logger->set_level(spdlog::level::warn);
				m_logger->flush_on(spdlog::level::warn);
			}
			else if (level == "error")
			{
				m_logger->set_level(spdlog::level::err);
				m_logger->flush_on(spdlog::level::err);
			}
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			std::cout << "Log initialization failed: " << ex.what() << std::endl;
		}
	}
 
	~XLogger()
	{
		spdlog::drop_all(); // must do this
	}
 
	void* operator new(size_t size)
	{}
 
	XLogger(const XLogger&) = delete;
	XLogger& operator=(const XLogger&) = delete;
 
private:
	std::shared_ptr<spdlog::logger> m_logger;
};
 
// use embedded macro to support file and line number
#define XLOG_TRACE(...) SPDLOG_LOGGER_CALL(XLogger::getInstance()->getLogger().get(), spdlog::level::trace, __VA_ARGS__)
#define XLOG_DEBUG(...) SPDLOG_LOGGER_CALL(XLogger::getInstance()->getLogger().get(), spdlog::level::debug, __VA_ARGS__)
#define XLOG_INFO(...) SPDLOG_LOGGER_CALL(XLogger::getInstance()->getLogger().get(), spdlog::level::info, __VA_ARGS__)
#define XLOG_WARN(...) SPDLOG_LOGGER_CALL(XLogger::getInstance()->getLogger().get(), spdlog::level::warn, __VA_ARGS__)
#define XLOG_ERROR(...) SPDLOG_LOGGER_CALL(XLogger::getInstance()->getLogger().get(), spdlog::level::err, __VA_ARGS__)
 
int main()
{
	// print log test, you can transfer any param to do format
	int param = 1;
 
	XLOG_TRACE("this is trace log record, param: {}", ++param); // int type param is ok
	XLOG_DEBUG("this is debug log record, param: {}", ++param);
	XLOG_INFO("this is info log record, param: {}", ++param);
	XLOG_WARN("this is warn log record, param: {}", double(++param)); // double type param is ok
	XLOG_ERROR("this is error log record, param: {}", std::to_string(++param)); // string type param is ok
 
	return 0;
}

// #include <iostream>
// // #include "Logger.h"
// #include <spdlog/sinks/basic_file_sink.h>
// using namespace std;
// int main(){
//     auto mylog = spdlog::basic_logger_mt("file_logger", "logs/basic-log.txt");
//     mylog->set_level(spdlog::level::info);
//     mylog->info("hello {}!","world!");
//     mylog->flush_on(spdlog::level::trace);
//     // spdlog::info("hello {}!","world!");
//     // spdlog::set_level(spdlog::level::debug);
//     // spdlog::info("spdlog version: {}", SPDLOG_VERSION);
//     // auto console_logger = spdlog::stdout_logger_mt("console");
//     return 0;
// }
// 创建一个日志记录器，这里使用console logger，将日志输出到控制台
// auto console_logger = spdlog::stdout_logger_mt("console");
// // 设置日志记录级别
//     spdlog::set_level(spdlog::level::debug);
// // template<class T>
// // class bigNumber;
// template<class T>
// bool cmp(const T& obj1, const T& obj2){
//     return !(obj1<obj2) && !(obj2<obj1);
// }

// template<class T=int>
// class bigNumber{
// public:
//     bigNumber(T num):num_(num){};
//     ~bigNumber(){};
//     bool operator<(const bigNumber& obj) const;
    
// private:
//     T num_;
// };
// template<class T>
// bool bigNumber<T>::operator<(const bigNumber& obj) const{
//     return this->num_<obj.num_;
// }
// int main(){
//     bigNumber<> a(1);
//     bigNumber<> b(1);
//     SPDLOG_DEBUG("a={}",a.num_);
//     SPDLOG_DEBUG("a={}",b.num_);
//     // std::cout<<cmp(a,b)<<endl;
//     SPDLOG_DEBUG("cmp(a,b)={}",cmp(a,b));
//     SPDLOG_DEBUG("cmp<double>(1,2)={}",cmp<double>(1,2));
//     // cout<<cmp<double>(1,2)<<endl;
//     return 0;
// }

//  给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。



//  例：s = “abcabcbb”，输出 3。
// abcdc

// 给你一个整数数组 nums ，
// 判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
// 同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。
// 输入：nums = [-1,0,1,2,-1,-4]
// -1 , 0 ,1

// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;

// class Solution{
// public:
//     vector<vector<int>>res;
//     void back(vector<int>&vec, int index, vector<int>path){
//         if(path.size()>3 || accumulate(path.begin(), path.end(), 0) != 0)return;
//         if(accumulate(path.begin(), path.end(), 0) == 0 || path.size()==3){
//             res.push_back(path);
//             return;
//         }
//         for(int i=index;i<vec.size();i++){
//             path.push_back(vec[i]);
//             back(vec, i+1, path);
//             path.pop_back(vec[i]);
//         }
//     }
// }

// int main(){
//     vector<int>vec = {-1,0,1,2,-1,-4};
//     Solution().back(vec, {}, 0)
//     return Solution().res;
// }


// // int method(string str){
// //     int maxLen = 0;
// //     int i=0, j=0;
// //     set<char> se;
// //     // int count =0;
// //     int j=i+1;
// //     for(int i=0;i<str.size();i++){
// //         int count =0;
// //         for(int j=i;j<str.size();j++){
// //             if(se.find(str[j]) != se.end()){
// //             maxLen = max(count, maxLen);
// //             break;
// //             // count =0;
// //             // i = j;
// //         }
// //         se.insert(str[i]);
// //         count++;
// //         }
        

// //     }
// // }
// // int main(){
// //     string str = "abcabcbb";
// //     return method(str);
// // }

// class A {int i;};
// class B {
//     A*p;
// public:
//     B(){ p = new A; }
//     ~B() { delete p; }
// };
// void sayHello(B& b){
//     cout << "Hello" << endl;
// } 
// int main() {
//     B b;
//     sayHello(b);
//     return 0;
// }

// int main(){
    
//     vector<pair<size_t, double>>res;
//     vector<double> find(const std::map<size_t, double>& value_map, size_t N){
//         map<size_t, double> ma;
//         for(auto x:value_map){
//             ma[x.second] = x.first;
//         }
//         auto it = ma.end();
//         for(int i=0;i<N;i++){
//             --it;
//             res.push_back(make_pair(it->second,it->first));
//         }
//     }
// }