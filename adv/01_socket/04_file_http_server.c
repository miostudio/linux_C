#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

#include <arpa/inet.h>
#include <pthread.h>

#define SMALL_BUF 1024
#define BUF_SIZE 2048

void* request_handler(void* arg);
void send_error(FILE* fp);
void send_data(FILE* fp, char* ct, char* file_name);
void error_handing(char msg[]);

int main()
{
	int serv_sock;                      // 服务器sock
	int clnt_sock;                      // 客户端sock
	struct sockaddr_in serv_addr;       // 服务器地址
	struct sockaddr_in clnt_addr;       // 客户端地址
	// 创建
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
		error_handing("socket() error");
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = 9000;                 // 端口
	serv_addr.sin_addr.s_addr = INADDR_ANY;    // ip
	// 绑定
	if (bind(serv_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
		error_handing("bind() error");
	// 监听
	if (listen(serv_sock, 5) == -1)
		error_handing("listen() error");
	while (1) {
		socklen_t clnt_addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (struct sockaddr*) & clnt_addr, &clnt_addr_size);
		printf("Connection Request :%s:%d\n",
			inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));
		pthread_t t_id;
		pthread_create(&t_id, NULL, request_handler, &clnt_sock);
		pthread_detach(t_id);
	}
 
	close(serv_sock);
	return 0;
}
//主函数与采用一客户端一线程的方法


//请求处理函数
void* request_handler(void* arg)
{
	int clnt_sock = *((int*)arg);
	FILE* clnt_read = fdopen(clnt_sock, "r");
	FILE* clnt_write = fdopen(dup(clnt_sock), "w");
	char req_line[SMALL_BUF];
	fgets(req_line, SMALL_BUF, clnt_read);
	if (strstr(req_line, "HTTP/") == NULL) {     // 查看是否是HTTP请求
		send_error(clnt_write);
		fclose(clnt_read);
		fclose(clnt_write);
		return NULL;
	}
	char method[10];
	char ct[15];
	char file_name[30];
	strcpy(method, strtok(req_line, " /"));      // 查看请求方法
	strcpy(file_name, strtok(NULL, " /"));       // 查看请求文件名
	strcpy(ct, content_type(file_name));         // 查看content-type
	if (strcmp(method, "GET") != 0) {
		send_error(clnt_write);
		fclose(clnt_read);
		fclose(clnt_write);
		return NULL;
	}
	fclose(clnt_read);
	send_data(clnt_write, ct, file_name);
}

//发送错误的函数
void send_error(FILE* fp)
{
	char protocol[] = "HTTP/1.0 400 Bad Request\r\n";
	char server[] = "Server: Linux Web Server \r\n";
	char cnt_len[] = "Content-length:2048\r\n";
	char cnt_type[] = "Content-type:text/html/r/n/r/n";
	char content[] = "<html><head><title>NETWORK</title></head>"
		"<body><font size+=5><br>发送错误！查看请求文件名和请求方式!"
		"</font></body></html>";
	fputs(protocol, fp);
	fputs(server, fp);
	fputs(cnt_len, fp);
	fputs(cnt_type, fp);
	fflush(fp);
}

//将一个HTML文件以及响应头拼接发送过去。
void send_data(FILE* fp, char* ct, char* file_name)
{
	char protocol[] = "HTTP/1.0 200 OK\r\n";
	char server[] = "Server:Linux Web Server \r\n";
	char cnt_len[] = "Content-length:2048\r\n";
	char cnt_type[SMALL_BUF];
	char buf[BUF_SIZE];
	sprintf(cnt_type, "Content-type:%s\r\n\r\n", ct);
	FILE* send_file = fopen(file_name, "r");
	if (send_file == NULL) {
		send_error(fp);
		return;
	}
 
	// 传输头信息
	fputs(protocol, fp);
	fputs(server, fp);
	fputs(cnt_len, fp);
	fputs(cnt_type, fp);
 
	// 传输请求数据
	while (fgets(buf, BUF_SIZE, send_file) != NULL) {
		fputs(buf, fp);
		fflush(fp);
	}
	fflush(fp);
	fclose(fp);
}

void error_handing(char msg[]){
	printf("%s\n", msg);
}

