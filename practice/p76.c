//输出当前文件执行代码
//__FILE__ 为当前执行的文件常量。
#include <stdio.h>
int main() {
    FILE *fp;
    char c;
	
	printf("String of __FILE__=%s\n", __FILE__);
	
    fp = fopen(__FILE__,"r");
    do {
         c = getc(fp);
         putchar(c);
    } while(c != EOF);
    
	fclose(fp);
    return 0;
}
