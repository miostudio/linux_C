#include<stdio.h>
#include<stdlib.h>
int main(){
  // 打开文件，获取句柄
  FILE *fp;
  char c;
  int n=0;
  fp=fopen("backup/test1.txt", "r");
  if(fp == NULL){
    printf("file open failed!\n");
	exit(1);
  }
  // 读取并打印文件
  //EOF是文件结尾的标志，此处判断是否到文件结尾
  while ((c=fgetc(fp)) != EOF ){
    printf("%c", c);
    n++;
  }
  
  printf("Read a file of length: %d\n", n);
  // 关闭文件
  fclose(fp);
  return 0;
}
