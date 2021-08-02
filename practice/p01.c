#include<stdio.h>
int main(){
	int i,j,z, counter=1;
	for(i=1; i<5; i++){
		for(j=1; j<5; j++){
			for(z=1; z<5; z++){
				if(i!=j && i!=z && j!=z){
					printf("%d %d%d%d\n", counter++, i,j,z);
				}
			}
		}
	}
	return 0;
}
