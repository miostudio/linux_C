#include<stdio.h>
// 浮点数在内存中的二进制形式

void print_red(char arr[]){
    printf("\033[31m%s\033[0m", arr);
}

void print_yellow(char arr[]){
    printf("\033[33m%s\033[0m", arr);
}

void print(char arr[], int counter){
    if(counter<=30 && counter>=23)
        print_red(arr);
    else
        print_yellow(arr);
}

/** 
 * modify from: https://blog.csdn.net/hbsyaaa/article/details/106970226
 * Aim: print binary format in memory of a given float
 * input: float
 * return: void
 */
void printf_binF(float num){
    int i, k;
    unsigned char j;
    int len=sizeof(float);
    //默认 小端，数字的低位放在地址低位
    //p先指向num后面的第4个字节的地址(0,1,2,3)
    unsigned char *p=(unsigned char*) &num + len-1;

    int counter=31;
    for(i=0; i<len; i++){ //依次处理4个字节(32位)
        //取每个字节的首地址，从高位到低位：p, p-1, p-2, p-3；
        //然后取值，正好是一个char，8bit
        j = *(p-i);

        for(k=7; k>=0; k--){ //k依次等于7,6,5,4,3,2,1,0
            //把1左移k位，然后和j取 并，如果j的这位上是1，则true
            if(j & (1<<k)){
                print("1", counter);
            }else{  //如果j的这位上为0，则false
                print("0", counter);
            }
            counter--;
        }
        printf(" ");//每8位加一个空格
    }
    printf("\n");
}


// 打印一个 float，及其在内存中的二进制表示
void bin_float(float c){
    //    c=1.11*2;
    printf("%s%f ", c>=0?" ":"", c);
    printf_binF(c);
}


int main(){
    //查看一个整数的ascii源码
    float a=2.42, b=-2.42;
    unsigned char *pa=(unsigned char*) &a, *pb=(unsigned char*) &b;

    printf( "sizeof(float)=%ld, sizeof(char)=%ld\n", sizeof(float), sizeof(char));

    // for a: 正数用原码
    for(int i=0; i< sizeof(float); i++){
        printf("%p[%d]=0x%x\n", &pa[i], i, pa[i]);
    }
    printf("\n");

    // for b: 负数用补码: 绝对值的原码，取反，再加1
    for(int i=0; i< sizeof(float); i++){
        printf("%p[%d]=0x%x\n", &pb[i], i, pb[i]);
    }
    printf("\n");

    // part II
    printf("float N在内存中的二进制表示，写成: N = (-1)^S * (1.M) * 2^(E-127) ，符号部分S, 阶码部分E，尾数部分M。 对二进制，2^n就是小数点的移位操作\n" 
        "\t符号位s(1 bit): 第31位，0表示正数，1表示负数\n");
    print_red("\t阶码位E(8 bits): 第30~23位，取值范围 -128~127：  阶码E = 指数e + 127 \n");
    print_yellow("\t尾数位M(23 bits): 第22-0位，换算成十进制就是 2^23=8388608，所以十进制精度只有6 ~ 7位。"
        "小数点前的1省略，相当于23位表示24位的内容\n\n");
    printf("\t2.42 = 1.21 * 2^1\n");

    printf("1.怎么确定符号位S？ \n");
    bin_float(a);
    bin_float(b);
    printf(" => 符号是整个浮点数的符号，仅仅体现在最高位(31th bit): 0正，1 负数。阶码E=1+127=128==2^7=10000000(2)\n");

    printf("\n2.怎么计算阶码E？把浮点数反复*2和/2写成1.xx * 2^e的形式，阶码E=e+127\n");
    bin_float(a/2);
    printf(" => 1.21=1.21*2^0，所以阶码E=0+127=127=2**7-1=01111111(2)\n");
    bin_float(0.605);
    bin_float(-0.605);
    printf(" => 0.605=1.21*2^-1，所以阶码E=-1+127=126=2**7-2=01111110(2)\n");
    
    bin_float(0);
    bin_float(0.5);
    bin_float(1);
    bin_float(2);
    bin_float(4);
    bin_float(8);
    printf(" => 只有指数部分 2^e, 指数e=-1,0,1,2,3, 则阶码E=e+127=126,127,128,1,2\n");

    bin_float(0.12);
    bin_float(1.92);
    printf(" => 0.12 = 1.92 * 2^-4， 阶码 E=-4+127, 就是把2^2扣掉(从右向左第3位)\n");

    printf("\n3.怎么计算尾数M？ 取出1.M中的M，开始反复 *2并取其整数部分作为2进制的高位\n");
    bin_float(2.5);
    bin_float(1.25);
    printf(" => 1.25=1.25*2^0, E=0+127; M=0.25, 0.25*2=0.5~整数0, 0.5*2=1.0~整数1，写起来就是 1.01，省略1，后面补0\n");

    printf(" => 0.87(10) = 1.101111(2) * 2^-1, 反复*2或除以2，写成 1.M * 2^e的形式，E=e+127\n");
    bin_float(0.87);
    bin_float(1.74);
    printf(" =>1.74=1.74 * 2^0; E=0+127; M=0.74，0.74*2=1.48~整数1，0.48*2=0.96~整数0，\n"
        "\t0.96*2=1.92~整数1，0.92*2=1.84~整数1，0.84*2=1.68~整数1，0.68*2=1.36~整数1，0.36*2=0.72~整数0，..."
        "==>1.1011110\n");

    return 0;
}

/*
例1: -12.5 的二进制表示
1. 通过反复*2或/2先化成 -12.5 = -1.5625 * 2^3
2. 符号位S: 负数最高位取1
3. 指数e=3，阶码E=e+127=130
3. 尾数部分 M=5625, 
0.5625*2=1.125 ~ 整数1
0.125*2=0.25 ~整数0
0.25*2=0.5 ~ 整数0
0.5*2=1.0 ~ 整数1
0 结束计算
尾数部分从高位到低位为 1.1001
4. 转化为IEEE754表示法：
   符号位：1
   指数位：127(偏移量/表示0)+3 = 130，即二进制10000010
   小数位：1001(去除了整数部分)，余下的位补0，即10010000000000000000000
5. 拼凑起来：1 10000010 10010000000000000000000




// 例2: 
比如：把十进制小数 0.87 转换成二进制，具体怎么操作？
1.通过反复*2或/2先化成 0.87 = 1.74 * 2^-1
2. 符号位 S=0
3. 指数e=-1, 阶码E=-1+127=126, 二进制 01111110
3. 尾数部分M=0.74
0.74*2=1.48 ~ 整数部分是1
0.48*2=0.96 ~ 0
0.96*2=1.92 ~ 1
0.92*2=1.84 ~ 1
0.84*2=1.68 ~ 1
0.68*2=1.36 ~ 1
0.36*2=0.72 ~ 0
0.72*2=1.44 ~ 1
0.44*2=0.88 ~ 0
0.88*2=0.76 ~ 0
...
从高位到低位写 1011110100
5. 拼凑起来: 0 01111110 1011110100...
*/