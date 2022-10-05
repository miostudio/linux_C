#include <stdio.h>
#include <stdlib.h>
//定义全局变量
int init_global_a = 1;
int uninit_global_a;
static int inits_global_b = 2;
static int uninits_global_b;
const int ci=125;
void output(int a)
{
	printf("hello");
	printf("%d",a);
	printf("\n");
}

int main( )
{   
	//定义局部变量
	int a=2;
	static int inits_local_c=2, uninits_local_c;
    int init_local_d = 1;
    output(a);
    char *p;
    char str[10] = "lyy";
    //定义常量字符串
    char *var1 = "1234567890";
    char *var2 = "qwertyuiop";
    int *var3 = (int*) 123456;
    //动态分配
    int *p1=malloc(4);
    int *p2=malloc(4);
    //释放
    free(p1);
    free(p2);
    printf("栈区-变量地址\n");
    printf("                a：%p\n", &a);
    printf("                init_local_d：%p\n", &init_local_d);
    printf("                p：%p\n", &p);
    printf("              str：%p\n", str);
    printf("\n堆区-动态申请地址\n");
    printf("                   %p\n", p1);
    printf("                   %p\n", p2);
    printf("\n全局区-全局变量和静态变量\n");
    printf("\n.bss段\n");
    printf("全局外部无初值  uninit_global_a：%p\n", &uninit_global_a);
    printf("静态外部无初值 uninits_global_b：%p\n", &uninits_global_b);
    printf("静态内部无初值  uninits_local_c：%p\n", &uninits_local_c);
    printf("\n.data段\n");
    printf("全局外部有初值  init_global_a：%p\n", &init_global_a);
    printf("静态外部有初值 inits_global_b：%p\n", &inits_global_b);
    printf("静态内部有初值  inits_local_c：%p\n", &inits_local_c);
    printf("\n文字常量区\n");
    printf("文字常量地址     ：%p\n",var1);
    printf("文字常量地址     ：%p\n",var2);
    printf("整型常量地址     ：%p\n",var3);
    printf("整型const地址    ：%p\n", &ci);
    printf("\n代码区\n");
    printf("程序区地址       ：%p\n",&main);
    printf("函数地址         ：%p\n",&output);
    return 0;
}
