#include <stdio.h>
int main(){
  int x=0;
  printf("0 x=%d\n", x);
  printf("1 x=%d\n", ++x);//now 1, return 1
  printf("2 x=%d\n", x++); //return 1, now 2
  printf("3 x=%d\n", x);
  return 0;
}
