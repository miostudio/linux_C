#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
void fatherFunc(){  // 父进程流程的主函数
    printf("\tThis is Father\n");
}

void childFunc() { // 子进程流程的主函数
    printf("\tThis is Son\n");
}

int main() {
    if (fork()>0) { 
        printf("这是父进程 %d，接着调用父进程特有函数=>\n", getpid() ); 
        fatherFunc();
    }
    else {
        printf("这是子进程 %d，接着调用子进程特有函数==>\n", getpid());
        childFunc();
    }

    sleep(1); 
    printf("父子进程执行完自己的函数后都来这里。\n"); 
    sleep(15);
}
/*
$ gcc a2_fork2.c 
$ ./a.out 
这是父进程 808309，接着调用父进程特有函数=>
        This is Father
这是子进程 808310，接着调用子进程特有函数==>
        This is Son
父子进程执行完自己的函数后都来这里。
父子进程执行完自己的函数后都来这里。


$ ps -ef | grep -P "a\.out"
wangjl    808309 3914767  0 15:08 pts/4    00:00:00 ./a.out
wangjl    808310  808309  0 15:08 pts/4    00:00:00 ./a.out
*/