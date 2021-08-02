#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	if(argc<2){
		printf("You must provide a long int!\n");
		return 1;
	}

	// 接收第一个参数，并字符串转为长整数
	float total=atof(argv[1]);
	printf("Your sales is %f\n", total);
	
	// 实际上，浮点数才够用
	float bonus=0, w=10000;
	float x1=10*w*0.1,
		x2=(total-10*w)*0.075,
		x3=(total-20*w)*0.05,
		x4=(total-40*w)*0.03,
		x5=(total-60*w)*0.015,
		x6=(total-100*w)*0.01;

	if(total<=10*w){
		bonus+= total*0.1;
	}else if(total>10*w && total <=20*w){
		bonus += x1+x2;
	}else if(total>20*w && total <=40*w){
		bonus += x1+x2+x3;
	}else if(total>40*w && total <=60*w){
		bonus += x1+x2+x3+x4;
	}else if(total>60*w && total <=100*w){
		bonus += x1+x2+x3+x4+x5;
	}else{
		bonus += x1+x2+x3+x4+x5+x6;
	}

	printf("Your bonus is %f\n", bonus );
	return 0;
}

