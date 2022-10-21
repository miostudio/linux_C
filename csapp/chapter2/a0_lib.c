/*
used in a6.c

*/

//打印1byte = 8bits的二进制表示
void show_byte(const unsigned char * ptr, int enter) {
    unsigned char j=*ptr;
    for(int i=7; i>=0; i--){
        printf("%s", (*ptr & (1<<i))==0? "0":"1" );
    }
    printf(" ");
    if(enter) printf("\n");
}

// 更一般的，支持打印任意个指定的字节
void show_bytes(void *p, int byteNum, int enter){
    unsigned char *ptr = (unsigned char *)p;
    //假设是小端，先打印最后一个字节
    for(int i=byteNum-1; i>=0; i--){
        show_byte( ptr + i, 0);
    }
    if(enter) printf("\n");
}