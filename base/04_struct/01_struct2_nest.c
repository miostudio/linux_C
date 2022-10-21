#include<stdio.h>
#include<string.h>

//1.结构体可以嵌套
struct Name{
  char first[10];
  char last[10];
};

struct Student{
    int id;
    struct Name name; //嵌套另一个结构体
    int age;
    char *addr; //字符指针
};

int main(){
    struct Student stu1={10, {"Hello", "Kitty"}, 18, "Beijing"}, stu2;
    printf("stu1 info: \tid:%d, name:%s-%s, age:%d, addr:%s\n", 
      stu1.id, stu1.name.first, stu1.name.last, stu1.age, stu1.addr);

    //2.同类的结构体变量能赋值
    stu2=stu1;
    stu2.id=22; //3.修改后不改变原来stu1.id的值, 说明是拷贝
    printf("stu2 info: \tid:%d, name:%s-%s, age:%d, addr:%s\n", 
      stu2.id, stu2.name.first, stu2.name.last, stu2.age, stu2.addr);
    
    //3.地址不一样,说明是拷贝
    printf("&stu1.age=%p, %p\n", &stu1.age, &stu1.addr);
    printf("&stu2.age=%p, %p\n", &stu2.age, &stu2.addr);
}