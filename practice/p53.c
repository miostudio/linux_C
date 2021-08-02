#include<stdio.h>
double addOdd(int n){
	printf("Odd\n");
	int i;
	double sum=0;
	for(i=1; i<=n; i+=2){
		sum += (double)1/i;
	}
	return sum;
}

double addEven(int n){
	printf("Even\n");
	int i;
	double sum=0;
	for(i=2; i<=n; i+=2){
		sum += (double)1/i;
	}
	return sum;
}

int main(){
	int num;
	printf("please input a number:");
	scanf("%d", &num);
	printf("num=%d\n", num);
	
	double sum=0;
	double (*pfunc)(int); //这是指向函数的指针
	if(0 == num%2){
		pfunc=addEven;
	}else{
		pfunc=addOdd;
	}
	sum=pfunc(num);
	printf("sum=%lf\n",sum);
	return 0;
}

