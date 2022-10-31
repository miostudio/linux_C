#include<stdio.h>
#include<string.h>

//四皇后问题: 国际象棋后能走直线，包括横竖和两个45度四种走法，给出4x4棋盘上4个后的（所有）放法，使其和平相处。
// 关键词: 回溯法、递归、深度优先搜索

#define MAX_V 105
int arr[MAX_V][MAX_V]; //棋盘
int Column[MAX_V], LeftTop[MAX_V], RightTop[MAX_V]; //列、主对角线、副对角线是否放元素
int counter=0;  //方案计数器

/* 难点分析: 
1. L和R两个向量啥意思?
  0  1  2  3
0
1
2
3
因为对行递归，所以保证每行有且只有1个棋子；
那么需要判断剩余3个方向:
1. 每列有且只有一个棋子，用C[j]判断
2. 2个对角线的本质，就是斜率为45和-45度的两条直线：(x,y)分别表示横竖坐标
    *主对角线: 斜率为-45度的直线，如果在一条直线上，则x-y是一个固定值，+NUM是为了保证为正
        过(0,0): (1,1) (2,2) (3,3): x-y=0
        过(1,0): (2,1) (3,2): x-y=1
        过(2,0): (3,1): x-y=2
        过(0,1): (1,2), (2,3): x-y=-1
        ...
    * 副对角线: 斜率为45度的直线，如果在一条直线上，则x+y是一个固定值
        过(0,1): (1,0): x+y=1
        过(0,2): (1,1), (2,0): x+y=2
        过(0,3): (1,2), (2,1), (3,0): x+y=3
        过(1,3): (2,2), (3,1): x+y=4

2. 递归过程中，全局变量被修改了怎么记录的？
arr 和 C, L, R 四个全局变量，实时更新的。
深度优先，就是沿着一个分支一直探索到终点，这个过程中设置并使用全局变量。
    当回来的时候，再把全局变量恢复。
搜索另一个分支时，全局变量也是使用最新的值。
函数内部的变量，则是保存在函数栈，栈消失则变量消失。
*/


//输出棋盘: 0表示没有棋子，正整数表示第n个皇后
void pintRec(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 深度优先搜索 deep first search：
/*
执行顺序：
调用是 DFS(0, 4)
  进入函数，对j循环
    j=0 时，可以进入 if，设置棋子[0,0]=1, C[0]=L[4]=R[0]=1。
        i=0<3，进入递归，探索第二行 DFS(1, 4)
            函数内 i=1是第二行，
              j=0时，C[0]=1 无法进入if
              j=1时，L[4]=1 无法进入if
              j=2时，可以进入if，设置棋子[1,2]=2, C[2]=L[3]=R[3]=1
                i=1<3，进入递归，探索第三行 DFS(2, 4)
                  函数内，i=2 第第三行
                    j=0, j=2的列都有棋子C[j]=1，无法进入if
                    j=1, 主对角线R[2+1]=R[3]=1，无法进入if
                    j=3，副对角线L[2-3+4]=L[3]=1，无法进入if
                该次试探结束，函数返回 DFS(2, 4) 空
                执行回退:去掉棋子 [1,2]=0, C[2]=L[3]=R[3]=0
              j=3时，可以进入if，设置棋子 [1,3]=2, C[3]=L[2]=R[4]=1
                状态 i=1<3, 进入递归，探索第 

*/
void DFS(int i, int num) { //i是行，共n个皇后
    for(int j=0; j<num; j++) { // j 对列循环
        // 如果无法进入 if， 则尝试下一列
        if(!Column[j] && !LeftTop[i-j+num] && !RightTop[i+j]) {  //安全，可以放
            //1. 试探放一个棋子
            arr[i][j]=i+1;  //放皇后，i+1表示该皇后属于第几个放的皇后：1-based number
            Column[j]=LeftTop[i-j+num]=RightTop[i+j]=1;
            // => 判断状态：是否递归
            if(i == num-1) {  //已经到最后一行，每一行都放了皇后
                pintRec(num); //输出棋盘
                counter++; //方案数加1
            } else {
                DFS(i+1, num); //递归--> 继续试探下一行: 第i+1行
            }
            //2. 试探完成后的回退
            arr[i][j]=0;
            Column[j]=LeftTop[i-j+num]=RightTop[i+j]=0;
        }
    }
}

int main() {
    // 1.输入n皇后
    int len;
    printf("Pls input the number of queens: num>=4 >>> ");
    scanf("%d", &len);
    // 2.初始化全局向量为0
    memset(arr, 0, sizeof(arr));
    memset(Column, 0, sizeof(Column));
    memset(LeftTop, 0, sizeof(LeftTop));
    memset(RightTop, 0, sizeof(RightTop));
	// 3.开始搜索，从第0行开始，放len个后
    DFS(0, len);
    //4. 打印方案总数
    printf("Total: %d solution(s)\n", counter);
    return 0;
}