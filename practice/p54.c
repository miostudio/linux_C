
#include<stdio.h>
int main(){
	char *words[]={"apple", "banana", "orange", "book"};
	char **ptr;
	int i;
	for(i=0; i<4; i++){
		ptr=&words[i]; //ptr 和 words[0] 是同一个东西，都是指向（字符数组的）指针的指针。
		printf("words[%d]: addr=%p->%p: %s\n", i, &words[i], words[i], words[i]);
		printf("  ptr[%d]: addr=%p->%p: %s\n", i, &ptr, *ptr, *ptr);
	}
}
