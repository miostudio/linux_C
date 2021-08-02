#include <stdio.h>
#include "03_small.c"


extern void printNew(){
  printf("*******\n");
}



int main(){
  printNew();
  printf("this is main: \n ");
  say();
  return 0;
}


