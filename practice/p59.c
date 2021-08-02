#include<stdio.h>
int A(int n, int k){
	int i=0, rs=1;
	if(0==k)
		return 1;
	while(k--){
		rs *= n;
		n--;
	}
	return rs;
}
int main(){
	int i, j, num, sum=4;
	for(i=2; i<=8; i++){
		num=4*6*A(6,i-2);
		printf("%d -> %d\n", i, num);
		sum+=num;
	}
	printf("总共的奇数个数是：%d\n", sum);
	return 0;	
}
