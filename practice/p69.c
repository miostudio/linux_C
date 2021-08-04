#include<stdio.h>
#include<string.h>
int main(){
	char *arr="this is a book, that is a cat! That fox jumps over this box.";
	char *sub="is";
	int n1=strlen(arr), n2=strlen(sub);
	
	int i,j, freq=0, flag;
	for(i=0; i<n1; i++){
		flag=1;
		for(j=0; j<n2; j++){
			if(arr[i+j] != sub[j] ){
				flag=0;
				break;
			}
		}
		if(flag){
			freq++;
			printf("第 %d 次匹配，匹配位置 %d\n", freq, i);
		}
	}
	printf("总匹配次数: %d\n", freq);
	return 0;
}
