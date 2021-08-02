#include<stdio.h>
int main(){
	int i,j, k;
	for(i='x'; i<='z'; i++){
		for(j='x'; j<='z'; j++){
			if(i==j) continue; //保证不能重复
			for(k='x'; k<='z'; k++){
				if(i==k || j==k) continue; //保证不能重复
				//保证满足条件
				if(i=='x') continue;
				if(k=='x' || k=='z') continue;
				printf("a-%c, b-%c, c-%c\n", i,j,k);
				
			}
		}
	}
	return 0;
}
