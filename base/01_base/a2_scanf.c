#include<stdio.h>
// v2 去掉数组
int main(){
    int sum=0;

    int a=90, b=100;
    printf("Input 3 integer between %d and %d\n", a, b);
    for(int i=0; i<3; i++){
        int temp;
        printf("> score %d: ", i);
        while(scanf("%d", &temp)==1){
            if(temp<90 || temp>100){
                printf("score must between %d and %d, input the %d score again:\n", a, b, i);
                printf("> score %d: ", i);
            }else{
                break;
            }
        }
        sum += temp;
    }
    printf("sum=%d\n", sum);
}