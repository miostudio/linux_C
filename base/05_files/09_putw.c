# include<stdio.h>
int main(){
	FILE *fp;
	fp=fopen("backup/test5.data","wb");
	int arr[]={10,2,30,-40};
	for(int i=0; i<4; i++){
		putw(arr[i], fp);
		printf("%d ", arr[i]);
	}
	fclose(fp);
	printf("saved with putw()\n");
	return 0;
}
