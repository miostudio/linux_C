#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	if(argc<2){
		printf("You must provide a long int!\n");
		return 1;
	}
	for(int i=0; i<argc; i++){
		printf("argv[%d]=%s\n", i, argv[i]);
	}
	long total=atol(argv[1]);
	//long total=argv[1];
	printf("you input:%ld\n", total);
}
