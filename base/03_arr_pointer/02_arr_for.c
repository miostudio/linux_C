#include<stdio.h>
int main(){
  int arr[]={10,11,12,13,14,15};
  for (int i=0; i<6; i++){
   printf("%d\n", arr[i]);
  }
  printf("===> %d\n", *arr);
 return 0;
}
