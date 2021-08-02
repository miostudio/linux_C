#include<stdio.h>
//static int *primers={2,3,5,7,11};

int isPrimer(int n){
	int i;
	for(i=2; i<n; i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

//test from n+1
int nextPrimer(int n){
	int i, flag;
	while(1){
		n++;
		if( isPrimer(n) ){
			return n;
		}
	}
}
void getNprimers(int N){
	int i, n=2;
	for(i=0; i<N; i++){
		printf("质数%d = %d\n", i, n);
		n=nextPrimer(n);
	}
}



int main(){
	//getNprimers(100);
	int num, i, j, flag;
	printf("请输入一个偶数: ");
	scanf("%d", &num);
	if(num<=0 || num%2!=0){
		printf("Error: must positive even!\n");
		return 1;
	}
	
	//开始分解
	flag=0;
	i=1;
	while(i<num){
		//保证一个是质数
		i=nextPrimer(i);
		//判断余下部分
		j=num-i;
		if(i>j){
			break;
		}
		
		if( isPrimer(j) ){
			flag=1;
			break;
		}
	}
	if(flag){
		printf("%d = %d + %d\n", num, i, j);
	}
		
	return 0;
}

