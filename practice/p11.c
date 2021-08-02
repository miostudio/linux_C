#include<stdio.h>
#include<math.h>
// is return 0; not return -1;
int isPrimer(int x){
	if(x<=0){
		printf("Error: please ensure x>0 !\n");
		return -1;
	}
	for(int i=2; i< (sqrt(x)+1); i++){
		if(x%i == 0){
			return -1;
		}
	}
	return 0;
}

int getNextPrimer(int x){
	while(1){
		x++;
		if(0==isPrimer(x)){
			return x;
		}
	}
}

int main(){
	int num;
	printf("please input a number:");
	scanf("%d", &num);
	printf("%d=", num);
	
	int primer=2; //质数
	while(num != 1){ //商
		int resid = num % primer; //余数
		while(resid==0){
			printf("%d", primer);
			num=num/primer;
			resid = num % primer;
			if(num!=1)
				printf("*");
		}
		primer=getNextPrimer(primer); //获取下一个质数
	}
	printf("\n");
	return 0;
}
