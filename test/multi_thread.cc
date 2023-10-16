#include<iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;
#include <iostream>

using namespace std;

class Base {
private:
    int m_;

public:
    Base() {
        m_ = 10;
        cout << "Base m_ is: " << m_ << endl;
    }
    void A(){
        cout<<"base A!"<<endl;
    }

    virtual ~Base() {
        cout << "Delete Base!" << endl;
    }
};

class Son :private Base { // 注意这里需要使用public继承
private:
    int mson_;

public:
    Son() {
        mson_ = 20;
        cout << "Son m_ is: " << mson_ << endl;
    }
    void A(){
        cout<<"Son A!"<<endl;
    }
    ~Son() {
        cout << "Delete Son!" << endl;
    }
};

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用迭代器删除元素
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it % 2 == 0) {
            cout<<it - vec.begin()<<" ";
            it = vec.erase(it); // 删除偶数元素，并返回下一个有效的迭代器
            cout<<*it<<endl;
            
        } else {
            ++it; // 移动到下一个元素
        }
    }

    // 打印剩余元素
    for (const auto& num : vec) {
        std::cout << num << " ";
    }

    return 0;
}

// std::mutex mt;
// int share = 0;
// void work1(){
//     while(share < 200) {
//         mt.lock();
//         // share++;
//         std::cout<< "线程1的share = " << share++ << std::endl;
//         usleep(100000);
//         mt.unlock();
//     }
// }

// void work2(){
//     while(share < 200) {
//         mt.lock();
//         // share++;
//         std::cout<< "线程2的share = " << share++ << std::endl;
//         usleep(100000);
//         mt.unlock();
//     }
// }

// int main(){
//     std::thread t1(work1);
//     std::thread t2(work2);
//     t1.join();
//     t2.join();
//     std::cout << "main thread! " << std::endl;
//     return 0;
// }
