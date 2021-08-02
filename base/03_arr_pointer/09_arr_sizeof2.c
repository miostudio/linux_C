# include<stdio.h>
int main(){
	int arr1[]={1,2,3,4,100};
	char arr2[][5]={"this", "is","a","book"};

	int N1=sizeof(arr1) / sizeof(1);
	printf("len(arr1)=%d\n", N1);
	for(int i=0; i<N1; i++){
		printf("arr1[%d] = %d \n", i, arr1[i]);
	}

	int N2=sizeof(arr2)/ sizeof( arr2[0] );
	printf("\nlen(arr2)=%d\n", N2);
	for(int j=0; j<N2; j++){
		printf("arr2[%d]=%s\n", j, arr2[j]);
	}
	
	return 0;
}
