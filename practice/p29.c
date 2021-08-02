#include<stdio.h>
int main(){
	char str[20], c, i=0;
	printf("please input a string:");
	//scanf("%s", str); getchar(); //吃掉回车键
	while( (c=getchar())!='\n' ){
		str[i]=c;
		i++;
	}
	str[i]='\0';
	
	char d;
	printf("please input a char you want to delete:");
	scanf("%c", &d);
	
	printf("str: %s, del: %c\n", str, d);
	
	//删除指定字符
	int n=i+1;
	for(int j=0; j<n; j++){
		if(str[j]==d){
			//后面的往前移动
			for(int i=j; i<n-1; i++){
				str[i]=str[i+1];
			}
			j--; //再次检查当前位置
		}
	}
	printf("after del %c, str: %s\n",d,  str);
	return 0;
}
