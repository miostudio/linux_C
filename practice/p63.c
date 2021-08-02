#include<stdio.h>
struct student{
    int x;
    char c;
} a;
void f(struct student b);

int main()
{
    a.x=3;
    a.c='a';
    f(a);
    printf("%d,%c\n",a.x,a.c);
}
void f(struct student b){
    b.x=20;
    b.c='y';
}
