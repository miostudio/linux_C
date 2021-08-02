#include<stdio.h>
// 回调函数a
void callback_a(int n){
    printf("Call callback_a, n: %d\n", n);
}

// 回调函数b
void callback_b(int n){
    printf("Call callback_b, n: %d\n", n);
}

// 回调动作
void callback_act(int x, void (*callback) (int var)){
    printf("Call callback_act, x: %d\n", x);
    callback(x);
}


void main(){
    int a = 1, b = 2;
    callback_act(a, callback_a);
    callback_act(b, callback_b);
    printf("Main program has done.");
}
