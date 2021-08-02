#include<stdio.h>
#include<stdlib.h>
//数字点阵
int digits[10][5][3] = { 
		{ {1,1,1},{1,0,1},{1,0,1},{1,0,1},{1,1,1} }, //0
		{ {0,1,0},{1,1,0},{0,1,0},{0,1,0},{1,1,1} }, //1
		{ {1,1,1},{0,0,1},{1,1,1},{1,0,0},{1,1,1} }, //2
		{ {1,1,1},{0,0,1},{1,1,1},{0,0,1},{1,1,1} }, //3
		{ {1,0,1},{1,0,1},{1,1,1},{0,0,1},{0,0,1} }, //4
		{ {1,1,1},{1,0,0},{1,1,1},{0,0,1},{1,1,1} }, //5
		{ {1,1,1},{1,0,0},{1,1,1},{1,0,1},{1,1,1} }, //6
		{ {1,1,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1} }, //7
		{ {1,1,1},{1,0,1},{1,1,1},{1,0,1},{1,1,1} }, //8
		{ {1,1,1},{1,0,1},{1,1,1},{0,0,1},{1,1,1} } //9
	};

//输入字符矩阵，打印
void printDigits(int *ptr, int nRow, int nCol){
	int i,j;
	for(i=0; i<nRow; i++){
		for(j=0; j<nCol; j++){
			char c = (0==*ptr)?' ':'*';
			printf("%c", c);
			ptr++;
		}
		printf("\n");
	}
}

//合并几个数字的点阵，间距是2列0.
int *combineDigits(int number, int spacer){
	//根据输入的数的长度，倒解连环
	int i=0, x[10], res;
	while(1){
		res=number % 10;
		x[i]=res;
		i++;
		number/=10;
		
		if(number<10){
			x[i]=number;
			break;
		}
	}
	//数组倒置
	for(int j=0; j< (i+1)/2; j++){
		int tmp=x[j], j2=i-j;
		x[j]=x[j2];
		x[j2]=tmp;
	}
	//逐个打印数组
	for(int j=0; j<=i; j++){
		printf("%d ", x[j]);
	}
	printf("\n");
	
	int n=i+1, nCol= 3*n+spacer*(n-1);
	//这个要注意返回的是最初的指针，而循环中指针一直在向后偏移。
	int *ptr0=malloc( sizeof(int)*5*nCol ), *ptr; 
	ptr=ptr0;
	for(int i=0; i<5; i++){
		for(int j=0; j<nCol; j++){
			int cur=x[j/(3+spacer)];
			
			int *digit= (int *)digits[cur];
			int r=j%(3+spacer);
			if( r<=2 ){
				*ptr=digit[i*3+r];
			}else{
				*ptr=0;
			}
			ptr++;
		}
	}
	return ptr0;
}


int main(int argc, char *argv[]){
	if(argc<2){
		printf("please provide a number [0, 9]\n");
		return 1;
	}
	//获取输入字符串，转为整数
	int num=atoi(argv[1]);
	printf("%d\n", num);
	
	if(num<0){
		printf("Error: x>=0\n");
		return 1;
	}else if(num<10){
		printDigits( (int *)digits[num], 5, 3 ); //传递参数时，要做指针类型转换
	}else if(num<1000*1000*1000){
		//2位到9位之间的
		int spacer=2;
		int *ptr=combineDigits(num, spacer);
		
		int n=0;
		while(num){
			n++;
			num/=10;
		}
		int nCol= 3*n+spacer*(n-1);
		printDigits( (int *)ptr, 5, nCol );
		free(ptr);
	}else{
		printf("Error: x<1e9\n");
		return 1;
	}
	return 0;
}
