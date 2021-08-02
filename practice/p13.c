#include<stdio.h>
int main(){
	int a,b, c;
	printf("input 2 numer, separate by blank:\n");
	scanf("%d %d", &a, &b);
	
	c=a*b;
	printf("(%d,%d)的最大公约数是", a,b);
	
	
	if(a<b){
		int t=a;
		a=b;
		b=t;
	}
	
	int r=a%b;
	while( 0 != r ){
		a=b;
		b=r;
		r=a%b;
	}
	printf("最大公约数是 %d, 最小公倍数是 %d\n", b, c/b);
}
