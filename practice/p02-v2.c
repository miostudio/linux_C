#include<stdio.h>
#include<stdlib.h>
#define WAN 10000

int main(int argc, char *argv[]){
	if(argc<2){
		printf("You must provide a long int!\n");
		return 1;
	}

	// 接收第一个参数，并字符串转为长整数
	double  total=atof(argv[1]);
	printf("Your sales is %lf\n", total);
	
	// 实际上，浮点数才够用
	double bonus=0;
	total /= WAN;
	double  x1=10*0.1,
		x2=(total-10)*0.075,
		x3=(total-20)*0.05,
		x4=(total-40)*0.03,
		x5=(total-60)*0.015,
		x6=(total-100)*0.01;
	
	if(total<=10){
		bonus+= total*0.1;
	}else if(total>10 && total <=20){
		bonus += x1+x2;
	}else if(total>20 && total <=40){
		bonus += x1+x2+x3;
	}else if(total>40 && total <=60){
		bonus += x1+x2+x3+x4;
	}else if(total>60 && total <=100){
		bonus += x1+x2+x3+x4+x5;
	}else{
		bonus += x1+x2+x3+x4+x5+x6;
	}
	printf("Your bonus is %lf\n", bonus*WAN );
	return 0;
}
