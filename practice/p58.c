#include<stdio.h>
int main(){
	char str[20], c;
	int i=0, j=0, sum=0;
	printf("请输入8进制数，不加首位的0:");
	while( (c=getchar())!='\n' && i<20 ){
		printf("%c", c);
		str[i]=c;
		i++;
	}
	for(j=0; j<i; j++){
		sum = sum*8 + (str[j]-'0');
	}
	printf("\nsum=%d\n", sum);
	return 0;
}
