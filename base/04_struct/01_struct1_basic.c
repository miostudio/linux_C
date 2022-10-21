#include<stdio.h>
#include<string.h>

//方法1: 定义结构体类型
struct Person{
  char name[10];
  int age;
  int arr[3];
};

void demo1(){
  // 声明结构体变量，并初始化
  struct Person p1 = {"Jim", 20, {1,20,300} };

  //引用结构体的成员。java 的类是不是就是这样实现的？
  printf("1) p1.name=%s, p1.age=%d\n", p1.name, p1.age);

  //改写成员的值
  //p1.name="Tom"; //error: assignment to expression with array type 字符串初始化格式，不能用于赋值。
  strcpy(p1.name, "Tom Smith");
  p1.age +=10;

  // 打印结果
  printf("2) p1.name=%s, p1.age=%d\n", p1.name, p1.age);
  for(int i=0; i<3; i++){
    printf("p1.arr[%d]=%d\n", i, p1.arr[i]);
  }
}

//方法2: 定义结构体类型，同时声明变量
struct Name{
  char first[10];
  char last[10];
} name1={"Bill", "Gate"}, name2={"Hello"};

void demo2(){
  printf("name1: %s-%s\n", name1.first, name1.last);
  printf("name2: %s-%s\n", name2.first, name2.last);
  //修改
  strcpy(name1.last, "Gates");
  strcpy(name2.last, "Kitty");
  printf("name1: %s-%s\n", name1.first, name1.last);
  printf("name2: %s-%s\n", name2.first, name2.last);
}

//方法3：不要类型名(不推荐，因为只能用一次，无法复用)
struct {
  char name[10];
  double price;
} book;

void demo3(){
  book.price=10.5;
  strcpy(book.name, "C lang");
  printf("book.name=%s, book.price=%f\n", book.name, book.price);
}


int main(){
  demo1();
  printf("\n");   demo2();
  printf("\n");   demo3();
}

