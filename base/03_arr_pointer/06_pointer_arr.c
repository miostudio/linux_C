#include<stdio.h>
int main(){
  int var[]={10,200,3000};
  int i, *ptr[3];
  for(i=0; i<3; i++){
    ptr[i]=&var[i]; 
  }
 
 for(i=0; i<3; i++){
   printf("value of var[%d]=%d or %d, pointer=%p\n", i, var[i], *ptr[i], ptr[i]);
 }
 return 0;
}

