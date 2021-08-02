#include <stdio.h>
int main(){
    int i,num;
    num=2;
    for(i=0;i<3;i++)    {
        printf("num = %d (%p) ", num, &num);
        num++;
		//花括号内变量的作用范围，离开失效。下次进来重新初始化
        {
            static int num=1;
            printf("内置模块 num = %d (%p) \n",num, &num);
            num++;
        }
    }
    return 0;
}
