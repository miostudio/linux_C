#include<stdio.h>

void test1(){
    for(int k=7; k>=0; k--){ //k依次等于7,6,5,4,3,2,1,0
        int a=1<<k;
        printf("[%d]%d\n",k, a);
    }
}


/** https://blog.csdn.net/hbsyaaa/article/details/106970226
 * Aim: print binary format in memory, for a given int
 * input: int
 * output: void
 */
void printf_bin(int num){
    int i, k;
    unsigned char j;
    int len=sizeof(int);
    //默认 小端，数字的低位放在地址低位
    //p先指向num后面的第4个字节的地址(0,1,2,3)
    unsigned char *p=(unsigned char*) &num + len-1;

    for(i=0; i<len; i++){ //依次处理4个字节(32位)
        //取每个字节的首地址，从高位到低位：p, p-1, p-2, p-3；
        //然后取值，正好是一个char，8bit
        j = *(p-i);

        for(k=7; k>=0; k--){ //k依次等于7,6,5,4,3,2,1,0
            //把1左移k位，然后和j取 并，如果j的这位上是1，则true
            if(j & (1<<k))  
                printf("1");
            else  //如果j的这位上为0，则false
                printf("0");
        }
        printf(" ");//每8位加一个空格
    }
    printf("\n");
}


void show(int a){
    printf("%s%d ", a>=0?" ":"", a);
    printf_bin(a);
}


int main(){
    //查看一个整数的ascii源码
    int a=3, b=-3;
    unsigned char *pa=(unsigned char*) &a, *pb=(unsigned char*) &b;

    printf( "sizeof(int)=%ld, sizeof(char)=%ld\n", sizeof(int), sizeof(char));

    // for a: 正数用原码
    for(int i=0; i< sizeof(int); i++){
        printf("%p[%d]=%x\n", &pa[i], i, pa[i]);
    }
    printf("\n");

    // for b: 负数用补码: 绝对值的原码，取反，再加1
    for(int i=0; i< sizeof(int); i++){
        printf("%p[%d]=%x\n", &pb[i], i, pb[i]);
    }
    printf("\n");


    // part II
    printf("int在内存中的二进制表示: \n");
    printf(" %d ", a);
    printf_bin(a);
    printf("%d ", b);
    printf_bin(b);

    test1(); //测试 << 运算符
    int c=755;
    printf("%d ", c);
    printf_bin(c);
    // 4位2进制 /bit => 1位16进制;  8bit=1byte=1char = 2个16进制位;
    printf("10进制: %d, \t8进制: 0%o, \t16进制: 0x%x  0x%X\n", c,c,c, c); 

    show(6);
    show(-6);

    return 0;
}