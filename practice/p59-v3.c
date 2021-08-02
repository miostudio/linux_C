#include<stdio.h>
int main(){
	int i, sum=4, num=4;
	for(i=2; i<=8; i++){
		if(i==2)
			num *= 7;
		else 
			num *= 8;
		sum+= num;
	}
	printf("总共的奇数个数是：%d\n", sum);
	return 0;	
}
