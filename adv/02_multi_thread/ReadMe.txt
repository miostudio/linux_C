
a1 getpid()  #include <unistd.h> //getpid, sleep
a2 fork() 创建新分支后，子进程和父进程同时进行，区分仅仅是 fork()的返回值
    1 一个 if 和 else 竟然同时执行了?
    2 就是靠 fork() 返回值区分在哪个进程的，0则是子进程，>0则在父进程
    3 父子进程的数据不受影响，复制后各管各的。

a3 练习 fork
    1 验证子进程是复制父进程的内存变量，还是父子进程共享内存变量？
    2 由父进程生成10个子进程，在子进程中显示它是第几个子进程和子进程本身的进程编号。
    3 由父进程生成子进程，子进程再生成孙进程，共生成第10代进程，在各级子进程中显示它是第几代子进程和子进程本身的进程编号。
    4 利用尽可能少的代码快速fork出更多的进程，试试看能不能把linux系统搞死 (答案是不能，会自动出现僵尸进程)
