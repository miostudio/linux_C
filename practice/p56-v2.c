#include<stdio.h>
int main(){
	int x=0,x1,x2,x3,x4,x5;
	for(x=1; ; x++){
		x1= (x-1)*4/5;
		x2= (x1-1)*4/5;
		x3= (x2-1)*4/5;
		x4= (x3-1)*4/5;
		//x5= (x4-1)*4/5;
		if( (x%5==1) && (x1%5==1) && (x2%5==1) &&(x3%5==1) &&(x4%5==1)){
			printf("total: %d\n", x);
			printf("每个人看到的总数: %d %d %d %d %d\n", x, x1, x2, x3, x4);
			break;
		}
	}
	return 0;
}
