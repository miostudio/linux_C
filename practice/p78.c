#include<stdio.h>
#include<math.h>
// 素数

//原始版本
void demo1(){
    int n,a;
    a=2;
    scanf("%d",&n);
    if(n<=2) {
        printf("ERROR");
    } else {
        while(a <= sqrt(n)) {
            if(n%a != 0) { 
                a++;
            }else{ 
                a=n+1;
                break; 
            }
        }
        if(a==n+1) {
            printf("%d is NOT a prime", n);
        } else {
            printf("%d is a prime", n);
        }
    }
    printf("\n");
}


//整理版本
int isPrimer(int n){
    int a=2;
    if(n<=2)
        return 0;

    while(a <= sqrt(n)) {
        if(n%a != 0)  a++;
        else  return 0;
    }
    return 1;
}


// 测试
void demo2(){
    int j=0;
    for(int i=2; i<101; i++){
        if(isPrimer(i)){
            printf("%d ", i);
            j++;
            if(j%10==0)
                printf("\n");
        }
    }
    printf("\n");
}


int main(){
    demo1();
    //demo2();
    return 0;
}

/*
$ gcc p78.c -lm

*/