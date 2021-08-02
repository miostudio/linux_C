#include<stdio.h>
//声明函数
int max(int a, int b);
int min(int a, int b);

int main(){
  int a=10, b=200;
  printf("the max is:%d\n", max(a, b));
  printf("the min is:%d\n", min(a, b));
}
