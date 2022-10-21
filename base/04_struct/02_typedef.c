#include<stdio.h>
#include<string.h>

// 另一种定义方式，给结构体一个别名
typedef struct{
  char name[10];
  int age;
} Person2;

// 结构体初始化，与指针
int main(){
 Person2  u2[5], *pu3;
 Person2 u1={"Tom", 20};
 pu3=&u1; //指针
 pu3->age += 100; //使用指针修改属性

 for(int i=0; i<5; i++){
   strcpy(u2[i].name, "Name");
   u2[i].age = i+10;
 }
 
 printf("u1: %s | %d (%p)\n", u1.name, u1.age, &u1); //直接引用 xx.name
 printf("u3: %s | %d (%p)\n", pu3->name, pu3->age, pu3); //使用指针变量引用 p->name

 printf("u2[1]: %s | %d\n", u2[1].name, u2[1].age);
 printf("u2[2]: %s | %d\n", u2[2].name, u2[2].age);
}

