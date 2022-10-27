#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h> //getpid, sleep
 
int main()
{
  printf("本程序的进程编号是：%d\n",getpid());
  sleep(30);    // 是为了方便查看进程在shell下用 ps -ef|grep a.out 查看本进程的编号。
}

/*
$ gcc a1_getpid.c
$ ./a.out
本程序的进程编号是：804315

$ ps -ef|grep a.out
wangjl    804315 3914767  0 14:40 pts/4    00:00:00 ./a.out
$ ps -ef| head -n 1
UID          PID    PPID  C STIME TTY          TIME CMD
*/