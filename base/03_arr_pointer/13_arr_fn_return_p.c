//从函数返回指针	C 允许函数返回指针到局部变量、静态变量和动态内存分配。
# include<stdio.h>

int *getArr(int size){
  //int arr[100]; //局部变量所占的内存地址便被释放了，因此当其函数执行完毕后，函数内的变量便不再拥有那个内存地址，所以不能返回其指针。
  static int arr[100];
  // 除非将其变量定义为 static 变量，static 变量的值存放在内存中的静态数据区，不会随着函数执行的结束而被清除，故能返回其地址。
  for(int i=0; i<size; i++){  arr[i]=i; }
  return arr;
}

int main(){
  int N=23;
  int *arr2=getArr(N);
  
  for(int i=0; i<N; i++){
    printf("%d ", arr2[i]);
  }
  printf("\n");
}
