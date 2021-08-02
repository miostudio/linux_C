#include<stdio.h>
int main(){
	int num, i,x=9;
	printf("input a primer:\n");
	scanf("%d", &num);
		
	for(i=1; i<20; i++){
		x = x*10 +9;
		if(x%num ==0){
			printf("%d / %d = %d 余数为0\n", x,num, x/num);
			break;
		}
	}
	return 0;
}
