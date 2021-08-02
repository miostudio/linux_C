#include<stdio.h>
void say(char string[]){
  printf("%s \n", string);
}

int main(){
  char string[]="this is a book";
  say(string);
  return 0;
}
