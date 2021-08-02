//指向指针的指针: 即在变量名前放置两个星号
#include<stdio.h>
int main(){
  int var=100;
  int *ptr=&var;
  int **pptr=&ptr;

  printf("value of var=%d(&var=%p)\n", var, &var);
  printf("value by *ptr=%d(ptr=%p, &ptr=%p)\n", *ptr, ptr, &ptr);
  printf("value by **pptr=%d(*pptr=%p, pptr=%p)\n", **pptr, *pptr, pptr);
  printf("sizeof(var)=%ld, sizeof(ptr)=%ld, sizeof(pptr)=%ld\n",sizeof(var), sizeof(ptr), sizeof(pptr));//4, 8, 8
 return 0;
}
