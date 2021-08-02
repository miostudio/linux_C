#include<stdio.h>
// 结构体作为函数参数
struct Student{
  char *name;
  int age;
};

void printS(struct Student s){
  printf("name:%s, age:%d, pointer:%p\n", s.name, s.age, &s); 
}

int main(){
  struct Student s1={"Tom", 21};
  
  printf("name:%s, age:%d, sizeof:%ld\n", s1.name, s1.age, sizeof(s1));

  s1.name = "Smith";
  printS(s1);
  
  s1.age += 20;
  printS(s1);
  return 0;
}
