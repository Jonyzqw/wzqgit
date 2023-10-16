#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork(); // 创建子进程

    if (pid == 0) { // 在子进程中
        // 构造参数列表
        char* const argv[] = {"./child_program", nullptr};

        // 调用 execv() 来加载新的程序代码
        if (execv("./app", argv) == -1) {
            perror("execv");
            exit(1);
        }
    } else if (pid > 0) { // 在父进程中
        // 父进程等待子进程结束
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            std::cout << "子进程退出，返回值为：" << WEXITSTATUS(status) << std::endl;
        }
    } else { // fork() 失败
        perror("fork");
        exit(1);
    }

    return 0;
}