#include<stdio.h>
// 回调函数就是把函数指针作为参数，传入函数

// 回调函数a
void callback_a(int n){
    printf("\tCall callback_a, n=%d\n", n);
}

// 回调函数b
void callback_b(int n){
    printf("\tCall callback_b, n=%d\n", n);
}

// 回调动作
void callback_act(int x, void (*callback) (int var)){
    printf("Call callback_act, x: %d\n", x);
    callback(x); //调用回调函数
}


void main(){
    int x = 1, y = 2;
    callback_act(x, callback_a);
    callback_act(y, callback_b);
    printf("Main program has done.\n");
}
