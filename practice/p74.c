#include<stdio.h>
int hanoi(int,char,char,char);
int move(char,int,char);

int main(){
    int n,counter;
    printf("Input the number of diskes：");
    scanf("%d",&n);
    printf("\n");
	
    counter=hanoi(n,'A','B','C');
    return 0;
}

//递归式调用
int hanoi(int n,char x,char y,char z){
    if(n==1)
        move(x,1,z);
    else{
        hanoi(n-1,x,z,y);//1.以z为中介，把n-1个从x移动到y上
        move(x,n,z); //2.把第n个从x移动到z
        hanoi(n-1,y,x,z); //3.以x为中介，把n-1个从y移动到z上
    }
    return 0;
}

//移动操作
// getFrom, 递归 step number, to
int move(char getone, int n, char putone){
    static int k=1; //移动步数
    printf("%3d:%3d # %c-->%c\n", k, n, getone,putone);
    if(k++%3==0)
        printf("\n"); //每移动三次换行
    return 0;
}
