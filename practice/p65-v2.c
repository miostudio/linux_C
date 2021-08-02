#include<stdio.h>
void swap(int *p1, int *p2){
	int tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}

int encode(int n){
	if(!(n>=1000 && n<=9999)){
		printf("Error: must be 4 digit number!\n");
		return -1;
	}
	//获取每位数字
	int i=0, arr[4];
	while(n>0){
		//进行加密1
		arr[i++] = (n%10 + 5) % 10;
		n/=10;
	}
	//加密2
	swap(&arr[0], &arr[3]);
	swap(&arr[1], &arr[2]);
	// 输出
	int rs=0;
	for(i=3; i>=0; i--){
		rs = rs *10 + arr[i];
	}
	return rs;
}

//解密
int decode(int n){
	if(!(n>=1000 && n<=9999)){
		printf("Error: must be 4 digit number!\n");
		return -1;
	}
	//获取每位数字
	int i=0, arr[4];
	while(n>0){
		//进行解密1
		arr[i++] = (n%10 - 5 +10) % 10;
		n/=10;
	}
	//解密2
	swap(&arr[0], &arr[3]);
	swap(&arr[1], &arr[2]);
	//输出
	int rs=0;
	for(i=3; i>=0; i--){
		rs = rs *10 + arr[i];
	}
	return rs;
}

int main(){
	int arr[]={1234, 9982, 3369};
	int i, N=sizeof(arr)/sizeof(int);
	int rs[3];
	
	//加密
	for(i=0; i<N; i++){
		rs[i]=encode(arr[i]);
		printf("%d after encoding is %d | decoding: %d\n", arr[i], rs[i], decode(rs[i]) );
	}
	return 0;
}

