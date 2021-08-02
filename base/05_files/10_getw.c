# include<stdio.h>
int main(){
	FILE *fp;
	fp=fopen("backup/test5.data","rb");
	int arr[4];
	for(int i=0; i<4; i++){
		arr[i]=getw(fp);
		printf("%d ", arr[i]);
	}
	fclose(fp);
	printf("\nread with getw()\n");
	return 0;
}
