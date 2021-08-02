#include<stdio.h>
int main(){
	float h=100, sum=h;
	int i=0;
	h/=2;
	for(i=2; i<=10; i++){
		sum+= h *2;
		h /= 2;
	}
	printf("共经过 %3.2f 米， 第十次反弹高度 %f 米\n", sum, h);
	return 0;
}
