/*
class derived-class: access-specifier base-class
- public、protected 或 private
- struct 关键字默认都是public 成员；class 关键字默认都是private 成员
*/

#include <iostream>

using namespace std;

// 基类
class Animal {
public:
    int leg;
    void setLeg(int num){
        leg=num;
    }
    int getLeg(){
        return leg;
    }
     void eat(){
         printf("Animal.eat()\n");
     }
    // sleep() 函数
    void sleep(){
         printf("Animal.sleep()\n");
     }
};


//派生类
class Dog : public Animal {
public:
    // bark() 函数：新方法
    void bark(){
         printf("Dog.bark()\n");
    }
    void eat(){ //覆盖掉父类的同名方法
        printf("Dog.eat()\n");
    }
};

int main(){
    //1.父类对象;
    Animal ani2;
    ani2.setLeg(5);
    printf("1>> ani2.getLeg()=%d\n", ani2.getLeg());
    ani2.eat();
    printf("\n");
    
    //2. Dog also has its father's functions
    Dog dog3;
    dog3.sleep(); 
    dog3.bark(); //子类的新功能
    dog3.eat(); //子类的eat方法
    printf("\n");

    //父类的指针可以指向父类或其子类，但是不能访问子类的成员
    Dog *d1=&dog3;
    d1->bark();
    //Animal *p1= (Animal*) &dog3; //父类的指针 指向其子类
    Animal *p1= &dog3; //父类的指针 指向其子类
    p1->eat(); // 调用的是父类的方法
    //p1->bark(); //error: ‘class Animal’ has no member named ‘bark’

    // 指针不能指向其父类，否则报错。但是强制类型转换后可以：https://www.bilibili.com/read/cv12154889
    //Dog *d2=&ani2; //error: invalid conversion from ‘Animal*’ to ‘Dog*’
    //d2->bark();
    Dog *d3=(Dog *)&ani2; //子类的指针指向可以通过强制类型转换指向其父类
    d3->bark();
    return 0;
}