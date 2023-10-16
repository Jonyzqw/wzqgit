#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
using namespace std;
int main(){
    //生成IPC键
    auto key = ftok("/tmp", 'P');
    //IPC_CREAT创建共享段
    auto shmid = shmget(key, 1024, 0666|IPC_CREAT);
    if(shmid == -1){
        perror("shmget");
        return 1;
    }
    // auto pid1 = fork();
    //将共享内存连接到当前进程的地址空间
    auto share_mem = shmat(shmid, NULL, 0);
    if(share_mem == (void*)-1){
        perror("shmat");
        return 1;
    }
    string str = "Helli world!";
    strncpy(static_cast<char*>(share_mem), str.c_str(), str.size());

    //分离共享内存
    shmdt(share_mem);

    auto pid = fork();
    if(pid == -1){
        perror("fork");
        return 1;
    }else if(pid == 0){
        //连接共享内存
        auto chile_share_mem = shmat(shmid, nullptr, 0);
        if(chile_share_mem == (void*)-1){
            perror("shmat");
            return 1;
        }
        cout<<"child receive data is : "<<static_cast<char*>(chile_share_mem)<<endl;

        
        //分离共享内存
        shmdt(chile_share_mem);
        //删除共享内存段
        shmctl(shmid, IPC_RMID, NULL);
        return 0;
    }

    wait(NULL);
    return 0;


    
}