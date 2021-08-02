//精细化
#include<stdio.h>
int main(){
	int a[3];
	printf("please input 3 numbers, separated by comma\n");
	scanf("%d,%d,%d", &a[0], &a[1], &a[2]);
	//排序
	int i,j;
	for(i=0; i<3; i++){
		for(j=i+1; j<3; j++){
			printf("==>i=%d, j=%d\n", i,j);
			if(a[i]>a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	//输出
	for(i=0; i<3; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
