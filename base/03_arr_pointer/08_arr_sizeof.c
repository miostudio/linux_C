#include<stdio.h>
// array and sizeof
int main(){
  printf("hello, sizeof\n");
  int a=10;
  int arr[]={1,20,300,4000};
  char c='C';  
  char name[]="Tom Hanks";
  
  printf("sizeof(int): %ld, sizeof(a): %ld\n", sizeof(int), sizeof(a)); //4
  printf("sizeof(arr): %ld\n", sizeof(arr)); //16
  printf("sizeof(char): %ld\n", sizeof(c)); //1
  printf("sizeof(name[]): %ld\n", sizeof(name) ); //10 包括最后一位 \0 也算进去了
   
 char arr2[][5]={"this", "is", "good"};
 printf("arr2: %ld, first ele: %ld\n", sizeof(arr2), sizeof(arr2[0]));
 
}
