//valgrind check
#include<stdio.h>
#include<stdlib.h>
int main(){
	int i, arr[]={1,27,34};
	int *p=malloc( sizeof(int) * 3);
	for(i=0; i<3; i++){
		p[i]=arr[i];
		printf("%d->%d\n", i, *(p+i));
	}
	return 0;
}
