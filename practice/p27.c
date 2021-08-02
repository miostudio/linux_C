#include<stdio.h>

int power(int a, int n){
	int i, rs=1;
	for(i=0; i<n; i++){
		rs*=a;
	}
	return rs;
}

int main(){
	int i,j, num, num0, arr[20];
	printf("input a number, 10 to 1e10:");
	scanf("%d", &num);
	
	//获取长度和每位是什么，如 123 -> {3,2,1}
	num0=num;
	i=0;
	while(num>0){
		arr[i]=num%10;
		i++;
		num/=10;
	}
	//倒序组装回去
	num=0;
	for(j=0; j<i; j++){
		printf("%d ", arr[j]);
		num+=arr[j]*power(10, i-j-1);
	}
	
	printf("\nbefore:%d, after:%d\n", num0, num);
	if(num==num0){
		printf("是\n");
	}else{
		printf("不是\n");
	}
	return 0;	
}
