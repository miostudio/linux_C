#include <stdio.h>
int main()
{
    unsigned a,b,c,d;
    printf("请输入整数：\n");
    scanf("%d",&a);
	printf("=>输入的: a=%d\n", a);
	
	//右移4位则
    b=a>>4;
	printf("=>右移四位后: b= %d\n", b);
	
	//~0就是1，左移4位是 (1000)2=8, 再取反是 (0111)2=4+2+1=7
    c=~(~0<<4);
	printf("=>取反，左移4位，取反: c=%d\n", c);
	
	//与运算 ()
    d=b&c;
	printf("=>b&c  %d & %d = %d\n", b,c, d);
	
    printf("a=%o\nd=%o\n",a,d);
    return 0;
}
