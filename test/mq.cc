#include <bits/stdc++.h>
template<class T>
class MessQue{
public:
    MessQue(){};
    ~MessQue(){};
    //插入任务
    void push_task(T task){
        std::unique_lock<std::mutex> lck(mutex_);
        Tasks_.push_back(task);
        //避免惊群效应
        cond_.notify_one();
    }
    //取出任务
    bool pop_task(T& task){
        std::unique_lock<std::mutex>lck(mutex_);
        if(!Tasks_.empty()){
            task = Tasks_.front();
            Tasks_.pop_front();
            return true;
        }
        return false;
    }
    //等待任务的出现
    void wait(T& task){
        std::unique_lock<std::mutex>lck(mutex_);
        while(Tasks_.empty())cond_.wait(lck);
        task = Tasks_.front();
        Tasks_.pop_front();
    }

    int size_(){
        std::unique_lock<std::mutex>lck(mutex_);
        return Tasks_.size();
    }

private:
    std::deque<T>Tasks_;
    std::mutex mutex_;
    std::condition_variable cond_;

};
class Task{
public:
    int type;
    void* param1;
    void* param2;
};
#include <functional>
int main(){
    int a =0;
    a += (a=8);
    std::cout<<a<<std::endl;
    // MessQue<Task> mq;
    // using consume = std::function<void()>;
    // // using consume = std::function(void());
    // consume method = [&](){
    //     Task t;
    //     while(1){
    //         mq.wait(t);
    //         std::cout<<"收到的任务类型为："<<t.type<<std::endl;
    //         if(t.type == 1001)break;
    //     }
    //     std::cout<<"线程退出！"<<std::endl;
    // };
    // std::thread t1(method);
    // //发送消息
    // printf("send number message to thread.1001 exit\n");
    // Task t;
    // while(1){
    //     std::cin>>t.type;
    //     mq.push_task(t);
    //     if(t.type == 1001)break;
    // }
    // t1.join();
    // return 0;
}