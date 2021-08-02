#include <stdio.h>
#include <string.h>

int main(){
 char str1[]="this is a book";
 int  len=strlen(str1);
 char *p=str1;
 int *ptr=NULL;

  printf("the pointer is %p\n", p);
  printf("the string is: %s, len=%d, char2=%c, char3=%c\n\n", 
	str1, len, str1[1], str1[2]);
 
 for(int i=0;i<len; i++){
  printf("arr[%d] = %c, pointer = %p\n", i, str1[i], &str1[i] );
 }

 printf("ptr is null, pointer = %p\n", ptr);
}

