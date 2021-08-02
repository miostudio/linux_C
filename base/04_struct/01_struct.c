#include<stdio.h>
#include<string.h>

//定义结构体
struct Person{
  char name[10];
  int age;
  int arr[3];
};


int main(){
  // 初始化结构体
  struct Person p1 = {"Jim", 20, {1,20,300} };
  //引用结构体的成员。java 的类是不是就是这样实现的？
  printf("1-> p1.name=%s, p1.age=%d\n", p1.name, p1.age);
  //p1.name="Tom";
  strcpy(p1.name, "Tom Smith");
  p1.age +=10;
  printf("2-> p1.name=%s, p1.age=%d\n", p1.name, p1.age);
  for(int i=0; i<3; i++){
    printf("p1.arr[%d]=%d\n", i, p1.arr[i]);
  }
}

