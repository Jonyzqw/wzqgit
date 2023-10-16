#include <bits/stdc++.h>
constexpr int MAX_SIZE = 10000;
// using MAX_SIZE = 10000;
class Queue{
private:
    int front;
    int rear;
    int arr[MAX_SIZE];
public:
    Queue():front(-1), rear(-1){};
    ~Queue(){};
    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return (rear+1) % MAX_SIZE == front;
    }
    void push(int val){
        if(isFull()){
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
        }else{
            
            if(isEmpty()){
                front = 0;
            }
            rear = (rear+1) % MAX_SIZE;
            arr[rear] = val;
            std::cout<<front<<" "<<rear<<std::endl;
        }
    }
    void pop(){
        if(isEmpty()){
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            
        }else{
             if(front == rear){
                front = -1;
                rear = -1;
             }else
                ++front;
        }
    }
    int get_front(){
        std::cout<<front<<std::endl;
        if(isEmpty()){
            return -1;
        }else{
            std::cout<<"arr[rear]"<<rear<<std::endl;
            return arr[rear];
        }
    }
    int back(){
        if(isEmpty()){
            return -1;
        }else{
            return arr[front];
        }
    }
};
int main(){
    std::deque<int>dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    std::cout<<dq.front()<<" "<<dq.back()<<std::endl;

    // Queue que;
    // que.push(1);
    // que.push(2);
    // que.push(3);
    // que.push(4);
    // std::cout<<que.get_front()<<std::endl;
    // std::cout<<que.back()<<std::endl;
    // que.pop();
    // que.pop();

}