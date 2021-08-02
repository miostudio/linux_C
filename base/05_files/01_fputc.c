#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
  FILE *fp;
  // 打开文件，指针相当于一个吸管，可以操作文件
  fp=fopen("backup/test1.txt", "w");
  if(fp == NULL){
    printf("file open failed!\n");
    exit(1);
  }
  
  //写入字符，一个一个写入
  char str[]="this is a line.\nthis is the 2nd line.\n";
  int index=0, N=strlen(str);
  while( index < N ){
    fputc( str[index++], fp);
  }
  printf("write %d char into file.\n", N);
  //关闭文件
  fclose(fp);
  return 0;
}
