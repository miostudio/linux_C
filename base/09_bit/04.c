#include <stdio.h>
int main()
{
    int a,b;
    a=234;
    b=~a;
    printf("a 的按位取反值为（十进制） %d\n",b);
	
    a=~a;
    printf("a 的按位取反值为（十六进制） %x (%d)\n",a,a);
    return 0;
}

