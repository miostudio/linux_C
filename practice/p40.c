#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define SQ(x) (x)*(x)

int main(){
	int num;
	int again=1;
	while(again){
		printf("input a number, if larger than 50, the script will stop:");
		scanf("%d", &num);
		printf("该数字的平方为 %d \n",SQ(num));
		if(num>50)
			again=FALSE;
		else
			again=TRUE;
	}
}
