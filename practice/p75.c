#include<stdio.h>
void del(int arr[], int len, int i){
	int j;
	for(j=i; j<len-1; j++){
		arr[j]=arr[j+1];
	}
}

int main(){
	int arr[30];
	int i;
	for(i=0; i<30; i++){
		arr[i]=i+1;
	}
	
	int counter=0, remain=30;
	while(remain>15){
		for(i=0; i<remain; i++){
			counter++;
			counter=counter%9;
			if(counter==0){
				printf("%d leave the boat\n", arr[i]);
				del(arr, remain, i); //数到9，则删除该元素i
				
				remain--;
				i--;
			}
			if(remain<=15){
				break;
			}
		}
	}
	return 0;
}
