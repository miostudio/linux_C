#include<stdio.h>
int main(){
    float f1=1.1;
    double d1=1.1;

    printf("sizeof float:%ld, double:%ld\n", sizeof(f1), sizeof(d1));
    printf("sizeof(1.1): %ld\n", sizeof(1.1) ); //浮点型常量都是按照双精度处理，分配8个字节

    float f2=3.1415926535897932;
    printf("f2=%lf\n", f2);

    //int x=y=z=3; //error: ‘y’ undeclared (first use in this function)

    int x,y,z;
    x=y=z=3;

    return 0;
}