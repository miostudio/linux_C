#include<stdio.h>
#include "max.h"
#include "min.h"

int main(){
  int a=10, b=-200;
  printf("the max is:%d\n", max(a, b));
  printf("the min is:%d\n", min(a, b));
}
