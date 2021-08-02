#include<stdio.h>
int getAge(int n){
	if(n==1)
		return 10;
	else
		return getAge(n-1)+2;
}

int main(){
	for(int i=1; i<=5; i++){
		int age = getAge(i);
		printf("the %d th man's age: %d\n", i, age);
	}
	return 0;
}
