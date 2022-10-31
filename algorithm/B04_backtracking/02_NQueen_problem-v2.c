#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//v1 不使用全局变量，解决N皇后问题
//v2 使用二级指针，代替变长数组
int counter=0; //统计方案总数的，可有可无变量

//打印棋盘结果: 0表示没有棋子，正整数表示第n个棋子
void printRec(int len, int **arr){
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            printf("%2d ", *(*(arr+i)+j) );
        }
        printf("\n");
    }
    printf("\n");
}

// 检查[i][j]位置放置棋子是否合法: 4个方向。
// 只需要检查已经填充的行（上方、左上、右上）。跳过未填充部分：都是0。
int isValid(int len, const int **arr, int row, int col){
    //1.递归保证了行合法: 每行有且只有一个棋子
    //2.当前列（上方）是否有棋子
    for(int i=0; i<row; i++ ){
        if(arr[i][col] != 0)
            return 0;
    }
    //3.判断主对角线(左上)是否有棋子
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
        if(arr[i][j] != 0)
            return 0;
    }
    //4.判断副对角线(右上)是否有棋子
    for(int i=row-1, j=col+1; i>=0 && j<len; i--,j++){
        if(arr[i][j] != 0)
            return 0;
    }
    return 1;
}

void DFS(int i, int len, int **arr ) { //第i行
	// 进入本函数时，在n×n棋盘前i-1行已放置了互不攻击的i-1个棋子
	// 现从第i行起继续为后续棋子选择合适位置
	// 1.当i==n时，求得一个合法的布局，输出之
	if (i==len) {
        printRec(len, arr); //输出棋盘的当前布局； //n为4时，即4皇后问题
        counter++;
	} else {
		for (int j=0; j<len; j++) { //第j列
			// 2.在第i行第j列放置一个棋子
            arr[i][j] = i+1;
            // 3.检查是否合法
			if (isValid(len, (const int **)arr, i, j)){
				DFS(i+1, len, arr); //如果合法，则探测下一行
            }
			// 4.移走第i行第j列的棋子
            arr[i][j] = 0;
		}
	}
}

int main(){
    // 1.输入 N 皇后
    int len;
    printf("Input an int [4, 20] >>> ");
    scanf("%d", &len);

    //2. 创建数组，保存棋盘状态: 0没有棋子，正整数表示第n个棋子
    //开辟一级指针的空间: row行，每行一个指针变量
    int **chessStatus=(int **)malloc( len * sizeof(int*)); 
    //开辟数据的空间: 每个指针指向 col 个int
    for(int i=0; i<len; i++){
        chessStatus[i]=(int *)malloc( len * sizeof(int));
    }

    // 3. 开始递归
    DFS(0, len, chessStatus);

    //4. 回收内存
    for(int i=0; i<len; i++) free(chessStatus[i]);
    free(chessStatus);

    printf("Total solution:%d\n", counter);

    return 0;
}
