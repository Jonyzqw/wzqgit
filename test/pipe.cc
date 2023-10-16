#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main(){
    int pipefd[2];
    int ret = pipe(pipefd);
    if(ret == -1){
        perror("pipe");
        return 1;
    }
    auto pid1 = fork();
    if(pid1 == -1){
        perror("fork");
        return 1;
    }else if(pid1 == 0){
        close(pipefd[0]);
        // int buf[1024];
        string str = "hello world!";
        write(pipefd[1], str.c_str(), str.size());
        close(pipefd[1]);
        return 0;
    }
    auto pid2 = fork();
    if(pid2 == -1){
        perror("fork");
        return 1;
    }else if(pid2 == 0){
        close(pipefd[1]);
        char buf[1024];
        // string str = "hello world!";
        auto res = read(pipefd[0], buf, sizeof(buf));
        if(res>0){
            buf[res] = '\0';
            cout<<"child 2 read data is : "<<buf<<endl;
        }else{
            cout<<"read fail!";
        }
        close(pipefd[0]);
        return 0;
    }
    wait(NULL);
    wait(NULL);
    return 0;
}