#include <stdio.h>
int main(int argc, char *argv[]){
	for(int i=0; i<argc; i++){
		//printf("input paras[%d]=%s\n", i, *(argv+i));
		printf("input paras[%d]=%s | %s\n", i, *(argv+i), argv[i]);
	}
	return 0;
}
