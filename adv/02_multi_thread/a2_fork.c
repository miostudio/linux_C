#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main() {
    printf("本程序的进程编号是：%d\n",getpid());

    int ipid=fork(); //获取新的进程，注意返回值：在父进程中，返回值是子进程编号；在子进程中，返回值是0。
    sleep(1);       // sleep等待进程的生成。
    printf("新进程 pid=%d\n", ipid);

    if (ipid!=0) {
        printf(">> 父进程编号是：%d\n", getpid());
    } else {
        printf(">> 子进程编号是：%d\n", getpid());
    }

    sleep(30); // 是为了方便查看进程在shell下用 ps -ef | grep -P "a\.out" 查看本进程的编号。
}

/*
$ gcc a2_fork.c 
$ ./a.out 
本程序的进程编号是：806255
新进程 pid=806256
>> 父进程编号是：806255
新进程 pid=0
>> 子进程编号是：806256

==> 怎么可能 if 和 else 都执行了？


$ ps -ef | grep -P "a\.out"
wangjl    806255 3914767  0 14:53 pts/4    00:00:00 ./a.out
wangjl    806256  806255  0 14:53 pts/4    00:00:00 ./a.out
*/