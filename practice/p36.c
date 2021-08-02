#include<stdio.h>

void test(int y){
	int i=0;
	static int i_static=0;
	i+=10;
	i_static+=10;
	printf("i=%d(%p), i_static=%d(%p), y=%d(%p)\n", i, &i, i_static, &i_static, y, &y);
}

int main(){
	int x;
	for(x=0; x<3; x++){
		test(x);
	}
	return 0;
}
