#include <stdio.h>
int main(){
	int x,y;
	for(x=2; x<168/2+1; x+=2){
		if(168%x !=0){ continue; }
		y=168/x;
		if(y%2!=0){ continue;}
		
		int p=(y-x)/2, t=(y+x)/2;
		if(p>t) {continue;}
		//printf("%d | x=%d, (%d**2), (%d**2)\n", x, p*p-100, p, t);
		printf("(%d) | %d + 100 = %d * %d\n", x, p*p-100, p, p);
		printf("(%d) | %d + 268 = %d * %d\n", x, p*p-100, t, t);
	}
}
