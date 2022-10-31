#include<stdio.h>
#include<stdlib.h>

//使用 malloc 模拟变长二维数组

void print2d(int row, int col, int **pA){
    printf("2-d array: %dx%d\n", row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            //printf("arr[%d][%d]=%d \t", i, j, pA[i][j]);
            printf("%3d ", pA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 设置值
void setNum(int **pA, int i, int j, int val){
    pA[i][j]=val;
}

void demo1(){
    //测试二维数组
    int row=4, col=3;
    //1. 开辟空间
    //开辟一级指针的空间: row行，每行一个指针变量
    int **chessStatus=(int **)malloc( row * sizeof(int*)); 
    //开辟数据的空间: 每个指针指向 col 个int
    for(int i=0; i<row; i++){
        chessStatus[i]=(int *)malloc( col * sizeof(int));
    }

    // 2.赋值
    int n=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            chessStatus[i][j]=n++;
        }
    }
    //设置某个值
    setNum(chessStatus, 1,2, 100);

    // 3. 打印
    print2d(row, col, chessStatus);

    //4. 回收内存
    for(int i=0; i<row; i++) free(chessStatus[i]);
    free(chessStatus);
}

int main(){
    demo1();
    return 0;
}