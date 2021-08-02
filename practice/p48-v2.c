#include<stdio.h>
void printArr(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void move2(int arr[], int n, int shift){
	int i, last;
	while(shift--){
		last=arr[n-1];
		for(i=n-1; i>=0; i--){
			arr[i]=arr[i-1];
		}
		arr[0]=last;
	}
}

//滚动数组，指向最后一个元素 arr+n
void move(int array[],int n,int offset){
    int *p,*arr_end;
    arr_end=array+n;   //数组最后一个元素的下一个位置
    int last;
    
    //滚动直到偏移量为0
    while(offset)
    {
        last=*(arr_end-1);
        for(p=arr_end-1; p!=array; --p)   //向右滚动一位
            *p=*(p-1);
        *array=last;
        --offset;
    }
}

int main(){
	int N=10, i;
	int arr[]={10,-26,38,-41,53,-64,-75,80,-98,106};
	int shift=0;
	printf("请输入后移量: ");
	scanf("%d", &shift);
	
	printArr(arr, N);
	// 偏移位置
	move(arr, N, shift);
	printArr(arr, N);	
}
