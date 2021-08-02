#include<stdio.h>
int main(){
	int num0,num, i=0, j, arr[6];
	printf("please input a number, 1 to 1e6: ");
	scanf("%d", &num);
	if(num<=0){
		printf("Error: must positive!\n");
		return 1;
	}
	
	num0=num;
	while(num>0){
		arr[i]=num%10;
		i++;
		num/=10;
	}
	printf("%d 是 %d 位数，逆序打印出各位数字: ", num0, i);
	for(j=0; j<i; j++){
		printf("%d", arr[j]);
	}
	printf("\n");
	return 0;
}
