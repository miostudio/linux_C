#include<stdio.h>
int main(){
  int sum=0, i;
  for (i=0; i<=100; i++){
    sum+=i;
  }
  printf("sum(0 to 100): %d\n", sum);
  return 0;
}
