#include<stdio.h>
#include<math.h>

//牛顿迭代法求平方根
double sqrt(double x){
    // https://www.demo2s.com/c/c-math-h-nan.html
    if(x<0) return NAN;

    double err=1e-20;
    double rs=x;
    int i=0;
    while( 0.25 * (rs - x/rs)*(rs - x/rs) > err){
        i+=1;
        rs=(x/rs + rs)/2;
        printf("%d %f %f\n", i, x, rs);
    }
    return rs;
}

int main(){
    double x;
    printf("Enter a positive number:");
    scanf("%lf", &x);

    double result=sqrt(x);
    printf("sqrt(%0.3f)=%0.10f\n", x, result);
    return 0;
}
