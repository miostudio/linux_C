//编写一个示例程序，由父进程生成10个子进程，在子进程中显示它是第几个子进程和子进程本身的进程编号。
#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h> //对 unix 的std 访问方法

int main(){
    int pid, i;
    for(i=0; i<5; i++){
        sleep(1);
        pid = fork();
        if(pid==0 || pid==-1){
            break; //子进程不创建子进程
        }
    }
    // 在子进程内显示
    if(pid==0) {
        // 显示 pid 和 父pid
        printf("son: number:%d, pid:%d, ppid=%d\n", i, getpid(), getppid());
    }else if(pid == -1){
        printf("error\n");
    }

    return 0;
}