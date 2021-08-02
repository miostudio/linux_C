#include <stdio.h>
int main(){
    int a,b, c;
    a=077;
    b=a&3;
    printf("%d & 3(decimal) 为 %d \n", a, b);
	
    c=b&7;
    printf("%d & 7(decimal) 为 %d \n", b, c);
    return 0;
}

