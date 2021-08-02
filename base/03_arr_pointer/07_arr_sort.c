#include<stdio.h>

void printArr(double arr[], int len){
  printf("[");
  for(int i=0; i<len; i++){
   //printf("arr[%d]=%2.1f\n", i, arr[i]);
    if(i<len-1){ printf("%2.1f, ", arr[i]); }
    else{ printf("%2.1f", arr[i] ); }
  }
  printf("]\n");
}

void sort(double arr[], int len){
 for(int i=0; i<len; i++){
  for(int j=i; j<len; j++){
    if( arr[i] > arr[j]){
      double tmp=arr[i];
      arr[i]=arr[j];
      arr[j]=tmp;
    }
   }
 }
}


int main(){
  double arr2[]={1.1, 1, 4.5, -5, 20, -2.1, 10, 2001, 1.3, -300};
  printf("arr is a pointer, %p\n", arr2);  

  printArr(arr2, 10);
  sort(arr2, 10);
  printArr(arr2, 10);
}


