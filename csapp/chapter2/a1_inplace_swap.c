#include<stdio.h>

// csapp-P38
//====== Part1 不使用第三个变量就交换了2个值
//这仅仅是一个智力游戏，没有性能的优势。
//使用性质 a^a=0, a^0=a, a^b^a=a^a^b=0^b=b;
void inplace_swap(int *x, int *y){
    //               a        b
    *y = *x ^ *y; // a        a^b
    *x = *x ^ *y; //a^a^b=b   a^b
    *y = *x ^ *y; //b         b^a^b=a
}

void demo1(){
    int x=10, y=20;
    printf("x=%d, y=%d\n", x, y);
    inplace_swap( &x, &y );
    printf("x=%d, y=%d\n", x, y);

}

//====== Part2: 通过交换，把数组首尾颠倒
void print_arr(int arr[], int len){
    printf("[");
    for(int i=0; i<len; i++){
        printf("%d%s", arr[i], i==len-1?"":",");
    }
    printf("]\n");
}

void reverse_array(int arr[], int len){
    int first, last;
    for(first=0, last=len-1;
        first<last; //如果这里加上<=则在数组长度是奇数时出错：导致中间始终是0
        first++, last--){
            inplace_swap(&arr[first], &arr[last]);
        }
}

void demo2(){
    //int arr2[]={1,2,3,4};
    int arr2[]={1,2,3,4, 5};
    int len=sizeof(arr2)/sizeof(int);
    print_arr(arr2, len);
    reverse_array(arr2, len);
    print_arr(arr2, len);
}


int main(){
    demo1();
    demo2();
    return 0;
}