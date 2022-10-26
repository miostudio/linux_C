#include<stdio.h>
#include <string.h>

// 怎么能方便的读取一行呢？还指定字符数
void demo1(){
    char msg[20];
    printf("Pls input a line> ");
    fgets(msg, 20, stdin);
    fputs(msg, stdout);

    printf("%s", msg); //看来自动加换行后缀？
}


//测试函数  strchr(const char *, int) 在参数1中找第二个字符，返回其第一次出现的地址
void demo2(){
    char msg[]="This is a book about C and its standard libraries";
    char *s1, *cur=msg;
    int j=0;
    while( s1=strchr(cur, 'i') ){
        printf("%p | %s\n", s1, s1);
        cur=s1+1;
        if(j++>20) break;
    }
}


//测试函数 getchar() 一次获取一个字符
void demo3(){
    char arr[20], arr2[20];
    printf(">> Pls input a string arr: ");
    int i=0;
    while(i++<5){
        arr[i]=getchar(); //如果不够5个，回车也不换行
    }
    //arr[i]='\0';
    printf("arr=%s | \n", arr);

    //为了防止第一行太长，影响第一个的输入
    while(getchar()!='\n')
        continue;

    printf(">> Pls input a string arr2: ");
    fgets(arr2, 20, stdin); //最后自带一个\n
    fputs(arr2, stdout);
    //printf("arr2=%s | \n", arr2);
}




//C primer plus 中最高频的函数，读取一行字符串到st指针，最长为n，末尾为\0
char* s_gets(char *st, int n){
    char *ret_val, *find;
    char tmp;
    ret_val = fgets(st, n, stdin); //读取一行，末尾可能会有\n
    if(ret_val){
        find = strchr(st, '\n'); //找到 \n 的位置下标
        if(find){
            *find = '\0'; //替换为字符串结尾
        }else{
            while( (tmp=getchar() )!= '\n'){ //忽略掉这一行其余的输入：应该是超过 int n个时起作用
                //printf("ignore char %c\n", tmp);
                continue;
            }
        }
    }
    return ret_val;
}

void demoN(){
    char arr[20];
    printf("Pls input arr=");
    s_gets(arr, 20);
    printf("arr=%s\n", arr);
}


int main(){
    //demo1();
    //demo2();
    demo3();
    //demoN();

    return 0;
}
