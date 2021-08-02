// 能接受指针作为参数的函数，也能接受数组作为参数
#include<stdio.h>

double mean(int *arr, int size){
  double sum=0;
  //int size=sizeof(arr) / sizeof(int); // 这个为什么不准呢？

  for(int i=0; i<size; i++){
    sum+=arr[i];
    printf("-->arr[%d]=%d, ", i, arr[i]);
  }
  printf("size=%d, sum=%f\n", size, sum);
 return(sum/size);
}

int main(){
 int arr[]={1,2,3,4};
 for(int i=0; i<4; i++){
  printf("%d ", arr[i]);
 }
 printf("\n");

 printf("The sum of arr is %f\n", mean(arr, sizeof(arr)/sizeof(1) ));
}
