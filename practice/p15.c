#include<stdio.h>
int getNum(int a, int n){
	int num=a;
	while(--n >0){
		num*=10;
		num+=a;
	}
	return num;
}

int main(){
	int a, n, i, sum=0;
	printf("input 2 number a and n, separate by blank\n");
	scanf("%d %d", &a, &n);
	
	for(i=1; i<=n; i++){
		int tmp=getNum(a, i);
		printf("%d\t", tmp);
		sum+=tmp;
	}
	printf(", sum is %d\n", sum);
	return 0;
}
