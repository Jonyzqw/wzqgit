#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode
// {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution
// {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 返回节点权值1个数比0的个数多一的路径数
//      * @param root TreeNode类 权值为0和1的二叉树根节点
//      * @return int整型
//      */
//     //     int count = 0;
//     int dfs_one(TreeNode *root, int one, int zero, int count)
//     {
//         if (!root)
//         {
//             if (one > zero)
//                 count++;
//             return count;
//         }
//         if (root->val == 1)
//             one++;
//         else
//             zero++;
//         int l = dfs_one(root->left, one, zero, count);
//         int r = dfs_one(root->right, one, zero, count);
//         // cout<<l<<" "<<r<<endl;
//         return l + r;
//     }
//     int dfs_zero(TreeNode *root, int one, int zero, int count)
//     {
//         if (!root)
//         {
//             if (one < zero)
//                 count++;
//             return count;
//         }
//         if (root->val == 1)
//             one++;
//         else
//             zero++;
//         int l = dfs_zero(root->left, one, zero, count);
//         int r = dfs_zero(root->right, one, zero, count);
//         return l + r;
//     }
//     int pathNumber(TreeNode *root)
//     {
//         // write code here
//         int zero = dfs_zero(root, 0, 0, 0);
//         int one = dfs_one(root, 0, 0, 0);
//         cout << zero + one << endl;
//         return zero + one;
//     }
// };
// // int main(){
// // //     Solution so;
// // //     so.pathNumber()
// //     vector<int>a{1,2,3,4,5};
// //     auto it = a.begin();
// //     it = it+3;
// //     a.erase(it);
// //     for(auto&x:a){
// //         cout<< x<<;
// //     }

// // }
// #include <iostream>
// #include <bitset>
// #include <bits/stdc++.h>

// #include <cstdlib>
// using namespace std;
// #include <sstream>
// string solve10_2(int n)
// {
//     string res = "";
//     while (n)
//     {
//         res += (n % 2) + '0';
//         n = n / 2;
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }
// string intToA(int n, int radix) // n是待转数字，radix是指定的进制
// {
//     string ans = "";
//     do
//     {
//         int t = n % radix;
//         if (t >= 0 && t <= 9)
//             ans += t + '0';
//         else
//             ans += t - 10 + 'a';
//         n /= radix;
//     } while (n != 0); // 使用do{}while（）以防止输入为0的情况
//     reverse(ans.begin(), ans.end());
//     return ans;
// }
// string solve_int_other(int n, int base)
// {
//     string res = "";

//     while (n != 0)
//     {
//         int t = n % base;
//         if (t < 10 && t >= 0)
//         {
//             res += (t) + '0';
//             n = n / base;
//         }
//         else
//         {
//             res += (t)-10 + 'A';
//             n = n / base;
//         }
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }
// int solve_other_int(string s, int base)
// {
//     // int res=0;
//     int ans = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] >= '0' && s[i] <= '9')
//             ans = ans * base + (s[i] - '0');
//         else
//             ans = ans * base + s[i] - 'A' + 10;
//     }
//     return ans;
// }

// int method(string s, int k)
// {
//     cout << s << " " << k << endl;
//     while (k > 0)
//     {
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '1')
//             {
//                 // cout<<s[i]<<" "<<"k"<<endl;
//                 s[i] = '0';
//                 k--;
//             }
//         }
//     }
//     return stoi(s, nullptr, 2);
// }
// // int main(){
// //     int n ;
// //     string s;
// //     cin>>s;
// //     cout<<solve_other_int(s,8)<<endl;
// //     // cout<<solve_int_other(n,16)<<endl;;
// //     // int n, k;
// //     // cin>>n>>k;
// //     // vector<int>arr(n,0);
// //     // int res=0;
// //     // for(int i=0;i<n;i++){
// //     //     cin>>arr[i];
// //     // }
// //     // string s1 = solve_int_other(arr[0], 16);
// //     // string s2 = solve_int_other(arr[1], 16);

// //     // cout<<s1<<" "<<s2<<endl;
// //     // cout<<method(s1, k);
// //     // res = min(method(s1, k)+arr[1], method(s2, k)+arr[0]);

// //     // cout<<res<<endl;
// // }
// // int main(int argc, char** argv){
// //     int n=9, i;
// //     for(int i=1;i<argc;i++){
// //         n = n*10 + *argv[i] - '0';
// //     }
// //     cout<<n<<endl;
// // }
// #include <iostream>
// #include <string>
// #include <sstream>

// // 通用模板
// template <typename T>
// T StringToNumber(const std::string &str)
// {
//     std::stringstream ss;
//     ss << str;
//     T result;
//     ss >> result;
//     return result;
// }

// // 模板特化：将字符串转换为整数（int）类型
// template <>
// int StringToNumber<int>(const std::string &str)
// {
//     return std::stoi(str);
// }

// // 模板特化：将字符串转换为长整数（long）类型
// template <>
// long StringToNumber<long>(const std::string &str)
// {
//     return std::stol(str);
// }

// // 模板特化：将字符串转换为浮点数（float）类型
// template <>
// float StringToNumber<float>(const std::string &str)
// {
//     return std::stof(str);
// }

// // 模板特化：将字符串转换为双精度浮点数（double）类型
// template <>
// double StringToNumber<double>(const std::string &str)
// {
//     return std::stod(str);
// }

// // int main() {
// //     std::string intStr = "42";
// //     std::string longStr = "1234567890123456789";
// //     std::string floatStr = "3.14";
// //     std::string doubleStr = "2.71828";

// //     int intValue = StringToNumber<int>(intStr);
// //     long longValue = StringToNumber<long>(longStr);
// //     float floatValue = StringToNumber<float>(floatStr);
// //     double doubleValue = StringToNumber<double>(doubleStr);

// //     std::cout << "int value: " << intValue << std::endl;
// //     std::cout << "long value: " << longValue << std::endl;
// //     std::cout << "float value: " << floatValue << std::endl;
// //     std::cout << "double value: " << doubleValue << std::endl;

// //     return 0;
// // }
// // int main(){
// //     int a[4];
// //     // *a;
// //     cout<<*(a++);

// // int arr[3][3] = {1,2,3,4,5,6,7,8,9};
// // int n = 3;

// // for(int i=0;i<n/2;i++){
// //     for(int j=i;j<n-i-1;j++){
// //         int temp = arr[i][j];
// //         // arr[n-1-j][i] = arr[n-1-j][n-1-i];
// //         arr[i][j] = arr[j][n-i-1];
// //         arr[j][n-i-1] = arr[n-i-1][n-j-1];
// //         arr[n-i-1][n-j-1] = arr[n-j-1][i];
// //         arr[n-j-1][i] = temp;
// //         // arr[i][j] = arr[n-j-1][i];
// //         // arr[n-j-1][i] = arr[n-1-i][n-j-1];
// //         // arr[n-1-i][n-1-j]= arr[j][n-1-i];
// //         // arr[j][n-1-i]  = temp;
// //     }
// // }
// // for(int i=0;i<3;i++){
// //     for(int j=0;j<3;j++){
// //         cout<<arr[i][j]<<" ";
// //     }
// //     cout<<endl;
// // }
// // }
// // unsigned int solve(){
// //     static unsigned int a = 0;
// //     static unsigned int b = 1;
// //     int c = a + b;
// //     a = b;
// //     b = c;
// //     return c;
// // }
// // class A{
// // public:
// //     static int  n;
// //     A(){
// //         n++;
// //     }
// //     ~A(){
// //         n--;
// //     }
// // };
// // int A::n = 0;
// int stoi_myself(string s)
// {
//     int ans = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         ans = ans * 10 + (s[i] - '0');
//     }
//     return ans;
// }
// const int N = 2E5 + 10, mod = 1e9 + 7;
// class A
// {
// public:
//     A() { cout << "A()" << endl; }
//     ~A() { cout << "~A()" << endl; }
// };
// class B : public A
// {
// public:
//     B() { cout << "B()" << endl; }
//     ~B() { cout << "~B()" << endl; }
// };

// class D
// {
// private:
//     static D *d;

// private:
//     D(){};

// public:
//     static D *getInstance()
//     {
//         if (d == NULL)
//             d = new D();
//         return d;
//     }
// };
// D *D::d = NULL;
// // A* A::a = NULL;

// template <class T>
// class OpNewCreator
// {
// public:
//     static T *create()
//     {
//         return new T;
//     }
// };

// template <class T>
// class MallocCreator
// {
// public:
//     static T *create()
//     {
//         void *buf = std::malloc(sizeof(T));
//         if (!buf)
//             return 0;
//         return new (buf) T;
//     }
// };

// template <template <class T> class Creators = OpNewCreator>
// class IntCreatorMgr : public Creators<int>
// {
//     int *create()
//     {
//         return Creators<int>().create();
//     }
// };
class  Solution{
public:
    vector<vector<int>>res;
    void back(vector<int>& candidates, int target, int index, int sum, vector<int> path,vector<bool> visit){
        if(sum>target)return;
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i = index; i<candidates.size();i++){
            if(i>0 && candidates[i] == candidates[i-1] && visit[i-1]== false)continue;
            sum += candidates[i];
            visit[i] = true;
            path.push_back(candidates[i]);
            back(candidates, target, i+1, sum,path, visit);
            visit[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<bool> visit(n, false);
        sort(candidates.begin(), candidates.end());
        back(candidates, target, 0,0, {},visit);
        return res;
    }
};
int main()
{
    vector<int>arr = {1,2,4,5,6,7};
    Solution so;
    vector<vector<int>>res = so.combinationSum2(arr, 7);
    for(auto x : res) {
        for(auto u : x){
            cout<<u<<" ";
        }
        cout<<endl;
    }


    // 使用OpNewCreator创建对象
    // int *obj1 ;
    // obj1 = OpNewCreator<int>::create();
    // std::cout << "使用OpNewCreator创建的对象：" << *obj1 << std::endl;
    // delete obj1;

    // // 使用MallocCreator创建对象
    // int *obj2 = MallocCreator<int>::create();
    // std::cout << "使用MallocCreator创建的对象：" << *obj2 << std::endl;
    // std::free(obj2);

    // return 0;
    // D::getInstance();
    // int a[] = {1, 2, 3, 4, 5};
    // int *ptr = (int*)(&a+1);
    // cout<<*(&a+1);
    // void func(char a[8]);
    // // char strVec[] = "Hello World";
    // cout<<sizeof(func(char a[8]))<<endl;
    // printf("%d %d", *(a+1), *(ptr-1));
    // cout<<sizeof(B)<<endl;
    // cout<<sizeof(C)<<endl;
    // vector<int>res;
    // cout<<res.size()<<endl;;
    // res.resize(3);
    // cout<<res.size()<<endl;;
    // res.push_back(100);
    // for(auto x : res){
    //     cout<<x<<endl;;
    // }
    // cout<<"sss";
    // int n, m;
    // double x,y;
    // int val;
    // string line;
    // stringstream ss;
    // getline(cin,line);
    // ss.str(line);
    // ss>>x;
    // ss>>y;
    // ss>>val;
    // cout<<x<<"-"<<y<<" "<<val<<endl;;

    // while(getline(cin,line)){
    //     ss.clear();
    //     ss.str(line);
    //     int x,y,c;
    //     string tmp;
    //     getline(ss,tmp,',');

    //     x = stoi(tmp);
    //     tmp.clear();
    //     getline(ss,tmp,',');
    //     y = stoi(tmp);
    //     tmp.clear();
    //     getline(ss,tmp,',');
    //     c = stoi(tmp);
    //     tmp.clear();
    //     cout<<x<<"-"<<y<<"-"<<c<<endl;

    // }

    // char a[10000];
    // char
    // cin>>n>>m;
    // cin.ignore();
    // for(int i=0;i<n;i++){
    //     int a,b, c;
    //     scanf("%d %d %d", &a,&b,&c);
    //     printf("%d%d%d",a, b, c);
    // }
    // int n;
    // vector<int>g[N];
    // int d[N];
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int a,b;
    //     scanf("%d:%d",&a,&b);
    //     g[b].push_back(a);
    //     d[a]++;
    //     if(i<n-1)getchar();
    // }
    // std::string name, team;
    // int score;

    // scanf("%s %s", name.c_str(), team.c_str());
    // cout<<name<<" "<<team<<endl;
    // int freq;
    // cin >> freq;
    // cin.ignore();
    // string line;
    // getline(cin, line);
    // stringstream ss(line);
    // while(getline(ss,)){
    //     if(line=="")break;

    //     double x, y;

    // }
    // string input;
    // cin.ignore();
    // getline(cin, input);
    // stringstream ss(input);
    // string token;
    // vector<pair<double, double>> time_points;
    // while (getline(ss, token, ',')) {
    //     stringstream tss(token);
    //     double f, l;
    //     tss >> f >> l;
    //     time_points.push_back({f, l});
    // }
    // string s;
    // int n;
    // cin>>n;
    // cin.ignore();
    // getline(cin, s);
    // stringstream ss;
    // ss<<s;
    // string teamA;
    // getline(ss,teamA,' ');
    // string teamB;
    // getline(ss, teamB, ' ');
    // cout<<teamA<<' '<<teamB<<endl;
    //     string line;
    //     map<string,string>ma;
    //     map<string,int>res;

    //     while (getline(cin, line)){
    //         if (line.empty()) {
    //             break;
    //         }
    //         stringstream ss;
    //         ss<<line;
    //         string name;
    //         getline(ss, name,' ');
    //         std::cout << "球星：" << name << std::endl;
    //         std::string team ;
    //         std::getline(ss, team, ' ');
    //         std::cout << "球队是" << team << std::endl;
    //         std::string score;
    //         std::getline(ss, score, ' ');
    //         std::cout << "得分：" << score << std::endl;
    //         // if(token == "0"){
    //         //     ma[id] = time;
    //         // }else{
    //         //     if(ma.find(id) != ma.end()){
    //         //         res[id] += stoi_myself(time) - stoi_myself(ma[id]);
    //         //         // cout<<"-----"<<endl;
    //         //         // cout<<res[id]<<endl;
    //         //     }
    //         // }

    //    }
    //    for(auto x:res){
    //     cout<<x.first<<" "<<x.second<<endl;
    //    }
}
// 101,1001,0
// 102,1001,0
// 102,1003,1
// 103,1001,0
// 101,1007,1
// 103,1009,1
// 101,1012,0
// 102,1012,0
// 101,1022,1
// 102,1022,1
