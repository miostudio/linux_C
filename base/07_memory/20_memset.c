#include<stdio.h>
#include <string.h>

//显示单字节的二进制
void show_byte(void *ptr){
    unsigned char *p=(unsigned char *)ptr;
    //printf("%p ", p);  //是否显示地址
    for(int i=7; i>=0; i--){
        printf("%s", (*p & (1<<i))?"1":"0" );
    }
    printf(" ");
}
//按小端，倒序显示n个字节的二进制：二进制高位在左边，二进制低位在右侧
void show_bytes(void *ptr, int len){
    unsigned char *p=(unsigned char *)ptr;
    for(int i=(len-1); i>=0; i--){
        show_byte( p + i); //printf("\n");
    }
}

//测试 显示二进制的函数
void demo1(){
    int arr[]={-1,0,1,2,3,4,8}, len=sizeof(arr)/sizeof(int);
    for(int i=0; i<len; i++){
        show_bytes(&arr[i], sizeof(int));
        printf(" %d \n", arr[i]);
    }
    printf("\n\n");
}

int main(){
    //demo1();
    int x=1, *p1=&x;
    printf(" x =%d | %p\n", x, &x);
    printf("*p1=%d | %p\n", *p1, p1);

    //show_byte(&x);     printf("\n\n");
    printf("\nAll from this status:\n");
    show_bytes(&x, sizeof(x)); printf(" x=%d\n", x);

    // 使用 memset 按字节设置值: 参数1 起始地址，参数2 要设置的值，参数 3 要设置几个字节 (byte)
    x=1; memset(&x, 0, sizeof(int)); //从某地址开始，设为0，长度为 4字节
    printf("\n1 After memset:\n"); show_bytes(&x, sizeof(x)); printf(" x=%d\n", x);
    
    x=1; memset( ((char *)&x)+1, 1, 1);//(小端，从左到右第二个字节)，设置为1，共1个字节
    printf("\n2 After memset:\n"); show_bytes(&x, sizeof(x)); printf(" x=%d\n", x);
    
    x=1; memset( ((char *)&x)+2, 8, 2);//(小端，从左到右第3个字节)，设置为8，共2个字节
    printf("\n3 After memset:\n"); show_bytes(&x, sizeof(x)); printf(" x=%d\n", x);
}