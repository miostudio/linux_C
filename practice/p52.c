#include<stdio.h>
#include<stdlib.h>
int power(int a, int n){
	int rs=1;
	while(n--){
		rs *= a;
	}
	return rs;
}

int main(){
	int num, num0;
	printf("输入一个整数:");
	scanf("%d", &num);
	num0=num;
	
	//获取长度
	int n=0;
	while(num >0){
		n++;
		num/=10;
	}
	
	//获取每一位
	int i, *pArr;
	pArr=malloc( sizeof(int)*n );
	num=num0;
	for(i=0; i<n; i++){
		*(pArr+i)=num%10;
		num /= 10;
	}
	//输出
	num=0;
	for(i=0; i<n; i++){
		num+=*(pArr+i)*power(10, n-1-i);
	}
	free(pArr);
	printf("%d 翻转后为 %d\n", num0, num);
	return 0;
}
