#include<stdio.h>
#include<unistd.h>
#include <stdlib.h> //exit() atoi()

//利用尽可能少的代码快速fork出更多的进程，试试看能不能把linux系统搞死

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Using:./a.out SecondTime\nExample:./a.out 15\n\n"); return -1;
    }
    int waitTime= atoi(argv[1]);  //最后等待时间

    int pid, i;
    for(i=0; i< 10; i++){ //生成 2^n 个进程
        pid=fork(); //主进程和子进程都可以开分支
    }

    if(pid==0) {
        printf(" >> [%d] 子线程: pid=%d, ppid=%d\n", i, getpid(), getppid());
        //sleep(3); //exit(0);
    } else{
        printf("[%d] 主线程: pid=%d, ppid=%d\n", i, getpid(), getppid());
        sleep(10);//主进程等待 其子进程都结束
    }

    /*
    2 4 2^2
    3 8 2^3
    4 16 2^4
    ...
    10 1024 2^10
    n       2^n
    */
    return 0;
}
