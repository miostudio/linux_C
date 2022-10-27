#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int ii=10;

int main() {
    int jj=20;

    if (fork()>0) {
        ii=110;
        jj=210; 
        sleep(1);  
        printf("Father: %d \n\tii=%d(%p), jj=%d(%p)\n", getpid(), ii, &ii, jj, &jj);
    } else {
        ii=-12;
        jj=-22; 
        sleep(1);  
        printf("Son: %d \n\tii=%d(%p), jj=%d(%p)\n", getpid(), ii, &ii, jj, &jj);
    }
}

/*
竟然地址一样！这还叫拷贝吗？
$ ./a.out
Father: 809373 
        ii=110(0x55f81266d010), jj=210(0x7ffdafdf5644)
Son: 809374 
        ii=-12(0x55f81266d010), jj=-22(0x7ffdafdf5644)
*/