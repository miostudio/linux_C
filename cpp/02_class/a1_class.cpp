/*
class derived-class: access-specifier base-class
- public、protected 或 private
- 
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
         printf("Animal.eat()");
     }
    // sleep() 函数
    void sleep(){
         printf("Animal.sleep()");
     }
};


//派生类
class Dog : public Animal {
    public:
    // bark() 函数
    void bark(){
         printf("Dog.bark()");
     }
};

int main(){
    Animal ani2;
    ani2.setLeg(5);
    printf("1>>%d\n", ani2.getLeg());
    ani2.eat();
    printf("\n");
    
    // Dog also has this function
    Dog dog3;
    dog3.sleep();
    printf("\n");
    dog3.bark(); //子类的新功能
    return 0;
}