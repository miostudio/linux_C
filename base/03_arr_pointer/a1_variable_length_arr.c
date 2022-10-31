#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//变长数组: https://blog.csdn.net/weixin_44788542/article/details/125799645


//打印数组
void printRec(int len, int (*arr)[len]){
    printf("\n%p\n", arr);
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            //printf("%2d ", *( *(arr+i)+j) );
            printf("%3d ", arr[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}

// 改变结果
void test(int i, int len, int arr[][len] ){
    for(int j=0; j<len; j++){
        arr[i][j]=i+j; //改变
        printf(">> log: set [%d %d] = %d \n", i, j, i+1);
    }
}

//定长数组
void demo1(){
    int len=4;
    int arr[4][4]={
        {1,2,3,4},
        {10,20,30,40}
    };

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    //using function
    printRec(len, arr);

    // 定义数组指针
    int (*pA)[len]=arr;
    printRec(len, pA);
    printf("sizeof: %ld, %ld\n", sizeof(arr), sizeof(pA));
}


// 变长数组
void demo2(){
    //变长数组的传参
    int len=4;    
    int (*pArr)[len]=(int (*)[len])malloc(sizeof(int)*len*len);
    //int (*pArr)[len]=malloc(sizeof(int)*len*len);
    printf("\n%p %p\n", pArr, *pArr);

    printf("sizeof: %ld\n", sizeof(*pArr));
    //归零
    memset(pArr, 0, sizeof(int)*len*len);
    printRec(len, pArr);
    //修改: 3种方法
    pArr[1][1]=3;
    *(*(pArr+1)+3)=-30;
    test(2, 4, pArr); //使用函数修改

    // 打印结果
    printRec(len, pArr);
    free(pArr);
}

int main(){
    //demo1();
    demo2();
    return 0;
}