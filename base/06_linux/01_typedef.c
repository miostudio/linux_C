#include<stdio.h>
int main(){
  typedef  int myInt;
  myInt a=12;
  printf("sizeof: %ld, %ld\n", sizeof(myInt), sizeof(a));
  return 0;
}
