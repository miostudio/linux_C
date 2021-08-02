#include<stdio.h>
#include<string.h>
int main(){
	char *toDay[]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	char input[5];
	int arr[7]={1,1,1,1,1,1,1}, n=7;
	printf("input from Monday to Sunday, any length is OK:");
	scanf("%s", input);
	
	//匹配
	int len=strlen(input), i=0, j=0;
	printf("your input is: %s, len=%d\n", input, len);
	while(len-- >0 ){
		if( 1==n ){
			break;
		}
		for(i=0; i<7; i++){
			if(arr[i]==0) continue;
			if( toDay[i][j] != input[j] ){
				arr[i]*=0;
				n--;
			}
		}
		j++;
	}
	//输出 
	printf("likely to be: ");
	for(i=0; i<7; i++){
		if(arr[i]>0){
			printf("%s\t", toDay[i]);
		}
	}
	printf("\n");
	return 0;
}
