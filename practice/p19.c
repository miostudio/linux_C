//失败，结果不能输出我们推测的结果。
#include<stdio.h>
int main(){
	char g1[3]={'a', 'b', 'c'};
	char g2[3]={'x', 'y', 'z'};
	int i,j;
	for(i=0; i<3; i++){
		char c1=g1[i];
		for(j=0; j<3; j++){
			char c2=g2[j];
			if(c1=='a' && c2=='x') continue;
			if(c1=='c' && (c2=='x' || c2=='z') ) continue;
			printf("%c vs %c\n", c1, c2);
		}
	}
	return 0;
}
