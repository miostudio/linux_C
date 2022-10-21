#include<stdio.h>

int main(){
    short a=-12345;
    unsigned short *b=(unsigned short *)&a;
    printf("sizeof short:%ld, u s:%ld\n", sizeof(a), sizeof(*b));
    printf("s=%d(%p), us=%u(%p)\n", a,&a, *b,b);
}

/*
s=-12345, us=53191
*/