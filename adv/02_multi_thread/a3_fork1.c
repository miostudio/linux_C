#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// 验证子进程是复制父进程的内存变量，还是父子进程共享内存变量？
int ii=10;

int main() {
    int jj=20;

    if (fork()>0) {
        sleep(1);
        for(; ii<jj; ii+=2){
            printf("Father: %d \tii=%d(%p), jj=%d(%p)\n", getpid(), ii, &ii, jj, &jj);
        }
    } else {
        for(; ii<jj; ii+=3){
            printf("Son: %d \tii=%d(%p), jj=%d(%p)\n", getpid(), ii, &ii, jj, &jj);
        }
    }
}