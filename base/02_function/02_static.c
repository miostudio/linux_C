#include<stdio.h>
void fn(){
  static int x=1;
  x*=2;
  printf("in fn x=%d\n", x);
}

int main(){
  int i;
  for (i=0; i<5; i++){
    fn();
  }
  
  extern int x;
  printf("x=%d\n", x);

 return 0;
}

int x=100;
