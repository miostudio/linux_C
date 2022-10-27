#include <stdio.h>   
#include <pthread.h>  
//#include <time.h>
//#include <windows.h>//使用Sleep的头
//#include <unistd.h>
/*
$ gcc 02.c -lpthread
*/
int g_number = 0;

#define MAX_COUNT 10000

pthread_mutex_t mut;

void *counter3(void* args) {
	int i = 1;
	while (i <= MAX_COUNT / 4) {
		pthread_mutex_lock(&mut);
		g_number++;
		printf("hi,i am pthread 3, my g_number is [%d]\n", g_number);
		pthread_mutex_unlock(&mut);
		//sleep(1);// 单位s
		i++;
	}
}

void *counter4(void* args) {
	int j = 1;
	while (j <= MAX_COUNT / 4) {
		pthread_mutex_lock(&mut);
		g_number++;
		printf("hi,i am pthread 4, my g_number is [%d]\n", g_number);
		pthread_mutex_unlock(&mut);
		//sleep(1);
		j++;
	}
}

int main() {
	printf("加互斥锁：线程安全的\n");
	pthread_mutex_init(&mut, NULL);
	pthread_t t3;
	pthread_t t4;
	pthread_create(&t3, NULL, counter3, NULL);
	pthread_create(&t4, NULL, counter4, NULL);

	getchar();
	return 0;
}
