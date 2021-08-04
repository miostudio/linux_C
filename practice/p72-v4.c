#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//输出字符串数组
void showArr(char arr[50][10], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%s ", arr[i]);
	}
	printf("\n");
}

//交换字符串
void swap_str(char *a, char *b){
	char tmp[10]; //字符串初始化必须指定大小，否则报错
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}

//对字符串数组排序
void sortArr(char arr[50][10], int n){
	int i, j, small;
	for(i=0; i<n-1; i++){
		small=i;
		for(j=i; j<n; j++){
			if( strcmp(arr[small], arr[j]) >0 ){
				small=j;
			}
		}
		if(small!=i){
			swap_str(arr[small], arr[i]);
		}
	}
}

//读取文件, 并用空格分割为字符串数组，放到指定数组中
//通过指针返回多个值
//bug1: 函数参数传递文件名，使用数组形式，不能使用 char *filename,
//bug2: p72-v4.c:29:9: error: array subscript is not an integer
//		*(arr[n] + i++)='\0'; 发现是传参数是*n，则使用的时候也要是 arr[*n]
//bug3: expected ‘char (*)[10]’ but argument is of type ‘char (*)[50][10]’
//		void readFile2Arr(char filename[], int *n, char arr[50][10]){} //二维数组怎么传参？
//		char arr[50][10]; readFile2Arr(filename, &len, arr); //为什么报错？

void readFile2Arr(char filename[], int *n, char arr[50][10]){
	FILE *fp=NULL;
	fp=fopen(filename, "r");
	if( fp==NULL ){
		printf("error: cannot open file!\n");
		exit(0);
	}
	
	//读文件
	char str;
	int i=0;
	while( (str=fgetc(fp))!= '\n' ){ //EOF
		if(str==' '){
			*(arr[*n] + i++)='\0';
			(*n)++;
			i=0;
		}else
			*(arr[*n] + i++)=str;
	}
	*(arr[*n] + i++)='\0';
	(*n)++;
	i=0;
	fclose(fp);
}


//写入文件
void save2File(char filename[], int n, char arr[50][10]){
	FILE *fp=NULL;
	fp=fopen(filename, "w");
	if( fp==NULL ){
		printf("error: cannot open file!\n");
		exit(0);
	}
	
	//写文件
	int i, j=0;
	char ch;
	for(i=0; i<n; i++){
		j=0;
		while( (ch=*(arr[i] + j++))!='\0' ){
			fputc(ch, fp);
		}
		fputc(' ', fp);
	}
	fputc('\n', fp);
	fclose(fp);
}


int main(){
	int len=0;
	char strArr[50][10];
	
	//读取第一个文件
	char fName1[20]="backup/A.txt";
	readFile2Arr(fName1, &len, strArr);
	showArr(strArr, len); //输出字符串
	
	//读取第二个文件
	char fName2[20]="backup/B.txt";
	readFile2Arr(fName2, &len, strArr);
	showArr(strArr, len); //输出字符串
	
	//按照字母顺序排序
	sortArr(strArr, len);
	showArr(strArr, len); //输出字符串
	
	//输出到文件
	char fName3[20]="backup/C.txt";
	save2File(fName3, len, strArr);
	
	return 0;
}
