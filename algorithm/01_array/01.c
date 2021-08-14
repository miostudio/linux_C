//查看元素在内存中的地址
#include <stdio.h>
int main(){
    int arr[5], i;

    printf("Size of integer in this compiler is %lu\n", sizeof(int));

    for (i = 0; i < 5; i++)
        // The use of '&' before a variable name, yields address of variable.
        printf("Address arr[%d] is %p\n", i, &arr[i]);
    return 0;
}
