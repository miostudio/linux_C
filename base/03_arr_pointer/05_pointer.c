#include<stdio.h>

int main(){
  int var[]={10,20,30,40}, n=4;

  int i, *ptr;
  ptr=var;
  printf("%p, value=%d, %d\n", var, *var, var[0]);

 for(i=0; i<n; i++){
  printf("value: var[%d]=%d, pointer=%p\n", i, *ptr, ptr);
  ptr++;
 }

  int *tmp;
  //tmp=(int*)0x7ffc72e3e074;
  tmp=var;
  printf("\n\n %d\n", *tmp); //Segmentation fault (core dumped)
 return 0;
}
