#include <stdio.h>
#include<string.h>
int main(int argc, char* argv[]){
	if(argc<3){
		return 101;
	}
	printf("input: |%s|, |%s|\n", argv[1],  *(argv+2));
	
	char c1[10], c2[10];
	strcpy(c1, argv[1]);
	strcpy(c2, argv[2]);
	printf("c1=|%s|, c2=|%s|\n", c1, c2);
	
	strcat(c1, c2);
	printf("combined: '%s'\n", c1);
	return 0;
}

