#include<stdio.h>
int getLeast(int wage){
	int i, money[]={100,50,10,5,2,1};
	int num[]={0,0,0,0,0,0}; //存储每张纸币的个数
	int count=0, resid=wage;
	for(i=0; i<6; i++){
		while(resid - num[i]*money[i] >=0 ){
			num[i]++;
		}
		if(num[i]>0){
			num[i]--;
			resid -= num[i]*money[i];
		}
		if(resid==0){
			break;
		}
	}
	for(i=0; i<6; i++){
		count += num[i];
	}
	printf("==> %d: %d\n", wage, count);
	return count;
}

int main(){
	int i, len=0, wage=0, number=0;
	scanf("%d", &len);
	for(i=0; i<len; i++){
		scanf("%d", &wage);
		number+= getLeast(wage);
	}
	printf("%d\n", number);
	return 1;
}
