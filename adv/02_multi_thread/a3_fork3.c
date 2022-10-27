//由父进程生成子进程，子进程再生成孙进程，共生成第10代进程，在各级子进程中显示它是第几代子进程和子进程本身的进程编号。
#include<stdio.h>
#include<unistd.h>

// https://blog.csdn.net/qq_18127085/article/details/117351845

int main() {
    int pid, i;
    for(i=0; i<10; i++){
        pid = fork();
        if(pid>0){
            //printf("[%d] 第[%d]代进程: pid=%d, ppid=%d\n", pid, i, getpid(), getppid());
            break; //父进程不再生成进程分支; 只有子进程生成
        }else if(pid==0){
            printf(">> [%d] 第[%d]代子进程: pid=%d, ppid=%d\n", pid, i, getpid(), getppid());
            //return 0; //从子进程返回
            //sleep(5); //子进程多等待一会，并不能阻止子进程很快结束: ps 查看
        }else{
            printf("Error\n");
        }
    }

    //让父进程等待10s，方便ps查看
    if(pid>0) 
        sleep(15);
    return 0;
}

/*
确实，下一个进程的父进程 ppid，是上一个进程的进程号 pid
$ ./a.out 
>> [0] 第[0]代子进程: pid=823106, ppid=823105
$ >> [0] 第[1]代子进程: pid=823120, ppid=823106
>> [0] 第[2]代子进程: pid=823127, ppid=823120
>> [0] 第[3]代子进程: pid=823131, ppid=823127
>> [0] 第[4]代子进程: pid=823140, ppid=823131
>> [0] 第[5]代子进程: pid=823154, ppid=823140
>> [0] 第[6]代子进程: pid=823166, ppid=823154
>> [0] 第[7]代子进程: pid=823171, ppid=823166
>> [0] 第[8]代子进程: pid=823180, ppid=823171
>> [0] 第[9]代子进程: pid=823185, ppid=823180
^C

问题：不能同时看到这几代进程，总是很快消失，只留下2个。
$ ps -ef | grep -P "a\.out"
wangjl    823154       1  0 16:24 pts/4    00:00:00 ./a.out 
wangjl    823166  823154  0 16:24 pts/4    00:00:00 ./a.out
# 父进程结束，如果子进程还没有结束，则其父进程变为 pid=1，原来是父进程结束的太快

$ ps -ef | grep -P "a\.out"
wangjl    823180       1  0 16:24 pts/4    00:00:00 ./a.out
wangjl    823185  823180  0 16:24 pts/4    00:00:00 ./a.out
*/