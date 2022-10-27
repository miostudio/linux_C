#include<stdio.h>
#include<stdlib.h>

/* 结构体数据文件的读写
重要函数 fprintf, fscanf
https://wenku.baidu.com/view/575ceb3151d380eb6294dd88d0d233d4b14e3f0b.html

年级	班级	姓名	身份证号
2020级	一班	岳飞	123321201001011234
2020级	二班	张飞	123321201001011235
2020级	三班	戚继光	123321201001011236
2020级	四班	林则徐	123321201001011237
*/

//定义结构体
struct Stu{
    char m_grade[10];
    char m_class[10];
    char m_name[12];
    char m_id[20];
};

//打印结构体
void print(struct Stu s){
    printf(">> struct Stu: \n  grade:%s, \n  class:%s, \n  name:%s, \n  id:%s \n", 
        s.m_grade, s.m_class, s.m_name, s.m_id);
}

void demo1(){ //保存数据
    //1.结构体赋值
    struct Stu s1[]={
        {"2020级",  "一班",  "岳飞",     "123321201001011234"},
        {"2020级",  "二班",  "张飞",     "123321201001011235"},
        {"2020级",  "三班",  "戚继光",     "123321201001011236"},
        {"2020级",  "四班",  "林则徐",     "123321201001011237"}
    };
    int len=sizeof(s1) / sizeof(struct Stu);
    //2.打印到屏幕
    printf("len: s1=%ld, Stu=%ld\n", sizeof(s1), sizeof(struct Stu)); //208 52
    for(int i=0; i<len; i++){
        print(s1[i]);
    }
    //3.打开文件
    FILE *fp=fopen("backup/stu_info.txt", "w");
    if(fp == NULL){
        printf("file open failed!\n");
        exit(1);
    }
    //4.保存表头
    struct Stu head={"年级",  "班级",  "姓名",     "身份证号"};
    fprintf(fp, "%s\t%s\t%s\t%s\n", head.m_grade, head.m_class, head.m_name, head.m_id);
    //5.保存内容
    for(int i=0; i<len; i++){
        fprintf(fp, "%s\t%s\t%s\t%s\n", s1[i].m_grade, s1[i].m_class, s1[i].m_name, s1[i].m_id);
    }
    //6.关闭内容
    fclose(fp);
}



void demo2(){ //读取数据
    //1.打开文件
    FILE *fp = fopen("backup/stu_info.txt", "r");
    if(fp == NULL){
        printf("file open failed!\n");
        exit(1);
    }
    //2. 第一次读取，获取总行数 https://www.csdn.net/tags/MtTacgxsNDM4NjItYmxvZwO0O0OO0O0O.html
    size_t len=0;
    size_t size=sizeof(struct Stu);
    char line[size];
    while( fgets(line, size, fp) ){
        //printf("line[%ld]: %s", len, line);
        len++;
    }
    printf("Total line:%ld, sizeof Stu:%ld\n", len, sizeof(struct Stu));

    // 3.把指针放到文件头
    rewind(fp); 
    // 4.逐行读取文件到结构体，并打印
    struct Stu stu;
    for(int i=0; i<len; i++){
        //读取文件一行，到结构体
        fscanf(fp, "%s\t%s\t%s\t%s\n", stu.m_grade, stu.m_class, stu.m_name, stu.m_id);

        //打印该结构体
        print(stu);
    }

    printf("\n");
    fclose(fp);
}

int main(){
    //demo1();
    demo2();
    return 0;
}