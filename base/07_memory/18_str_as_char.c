#include<stdio.h>
#include<string.h>
void show_bytes(unsigned char * start, size_t len){
    size_t i;
    for(i=0; i<len; i++){
        printf(" %.2x", start[i]); //todo??
    }
    printf("\n");
}

void test1(){
	char p[] ={'1', '2', '3', '4', '5', '\0'};
    printf("%s\n", p);
    show_bytes( (unsigned char *) p, sizeof(p) ); //获取数组的长度 = 字符串长度+1
}

void test2(){
	const char *p ="12345";
    printf("%s\n", p);
    show_bytes( (unsigned char *) p, strlen(p)+1 );//实际占用长度 = 字符串长度 + 1
}

void test3(){
	const char *p ="abcdef";
    printf("%s\n", p);
    show_bytes( (unsigned char *) p, strlen(p)+1 );
}

int main(){
    test1();
	test2();
    test3();

    return 0;
}