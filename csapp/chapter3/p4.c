#include<stdio.h>
int main(){
    int arr[2][3]={
        {-1, 0, 2},
        {-4, 0, 8},
    };
    int (*pArr)[3]=arr; //看不懂汇编

    printf(" arr[1][2]=%d,  &arr[1][2]=%p\n", arr[1][2], &arr[1][2]);
    printf("pArr[1][2]=%d, &pArr[1][2]=%p\n", pArr[1][2], &pArr[1][2]);
    /*
    //
    printf("  *(*(arr+1)+2)=%d,   (*(arr+1)+2)=%p\n", *(*(arr+1)+2), *(arr+1)+2 );
    printf(" *(*(pArr+1)+2)=%d,  (*(pArr+1)+2)=%p\n", *(*(pArr+1)+2), *(pArr+1)+2);
    */

    return 0;
}
/*
$ gcc p4.c
$ objdump -d a.out



*/