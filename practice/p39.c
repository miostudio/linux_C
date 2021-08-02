#include <stdio.h>
int main(){
    register int i;
    int tmp=0;
    for(i=1;i<=100;i++)
        tmp+=i;
    //printf("总和为 %d, i=%d(%p)\n",tmp, i, &i);
    printf("总和为 %d, i=%d\n",tmp, i);
    //p39.c:7:5: error: address of register variable ‘i’ requested
    return 0;
}
