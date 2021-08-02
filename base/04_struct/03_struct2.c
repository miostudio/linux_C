#include<stdio.h>
struct Person{
 char *name;
 int age;
 int arr[10];
};

int main(){
  struct  Person p1={"Tom", 20, {1,22,333}};
  printf("sizeof(Person)=%ld, pointer=%p\n", sizeof(p1), &p1);

  p1.name="Tompson";
  printf("name:%s, age=%d\n", p1.name, p1.age);
  

  int iT1[] = {-1,-20,-3,-40,-5,60,7,80,9,100};
  for(int i=0; i<10; i++){
    p1.arr[i] = iT1[i] + p1.arr[i];
  }

  for(int i=0; i<10; i++){
    printf("p1.arr[%d]=%d\n", i, p1.arr[i]);
  }

}
