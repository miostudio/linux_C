#include<stdio.h>
int power(int a, int n){
	int rs=1;
	if(0==n){
		return 1;
	}
	while(n--){
		rs*=a;
	}
	return rs;
}
int main(){
	int i, sum=4, num;
	for(i=2; i<=8; i++){
		num=4*(8-1)*power(8, i-2);
		sum+= num;
	}
	printf("总共的奇数个数是：%d\n", sum);
	return 0;	
}
