//传递指针给函数
//C 语言允许您传递指针给函数，只需要简单地声明函数参数为指针类型即可。
#include<stdio.h>

// 在函数内改变某参数的值
void add(int *a, int *b){
 *a=*a+*b;
}


int main(){
 int n1=100, n2=20;
 int *p1=&n1, *p2=&n2;
 printf("1-> n1=%d, n2=%d\n", n1, n2);

 add(&n1, &n2);
 printf("2-> n1=%d, n2=%d\n", n1, n2);

 add(p1, p2);
 printf("3-> n1=%d, n2=%d\n", n1, n2);

 return 0; 
}
