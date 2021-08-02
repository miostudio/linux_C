#include<stdio.h>
int main(){
  int i, sum=0;
  i=1;
  while( i<=100){
    sum+=i;
    i+=1;
  }

  printf("sum of 1 to 100 is %d\n", sum);
 return 0;
}
