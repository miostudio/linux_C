#include<stdio.h>
int main(){
	int num=63;
	printf("10进制: %d\n", num);
	printf("16进制: 0x%X\n", num);
	printf("16进制: 0x%x\n", num);
	printf("8进制: 0%o\n", num);
	//printf("2进制: %b\n", num);
	printf("2进制(没): %p\n", &num);

	// printf()8进制、16进制输出格式控制：
	printf("%04o\n",num); /*输出4位8进制的num*/
	printf("%02X\n",num); /*输出2位16进制的num*/
	return 0;
}
