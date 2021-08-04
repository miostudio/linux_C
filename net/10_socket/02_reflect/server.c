#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

#include <arpa/inet.h>
/*
fix1 所有错误都不能返回0
update1 发送回客户端
*/

#define MAXLINE 4096

int main(int argc, char** argv){
    int  server_sockfd, client_sockfd; /* 之前命名 listenfd 服务端监听, connfd 客户端连接;*/
    struct sockaddr_in  servaddr;
    char buff[4096];
    int  len;

    if( (server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9000);

    if( bind(server_sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 1;
    }

    if( listen(server_sockfd, 10) == -1){
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 1;
    }

    printf("======waiting for client's request======\n");
    while(1){
		/*客户端连接上*/
		if( (client_sockfd = accept(server_sockfd, (struct sockaddr*)NULL, NULL)) == -1){
			printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
			continue;
		}
		//发送连接欢迎信息		
		printf("###### accept client %s\n",inet_ntoa(servaddr.sin_addr));
		len=send(client_sockfd,"Welcome to my server\n",21,0);
		
		while( (len = recv(client_sockfd, buff, MAXLINE, 0))>0 ){
			buff[len] = '\0';
			printf("recv msg from client: %s\n", buff);
			
			//收到消息是 quit，则关闭客户端连接
			if(!strcmp(buff,"quit\n")){
				close(client_sockfd);
				printf("Client is quiting now ...\n");
				break;
			}
			
			// 发送回客户端
			if(send(client_sockfd, buff, len, 0)<0){
				printf("write error\n");
				return 1;
			}	
		}
    }
	
	/*关闭套接字*/
    close(server_sockfd);
    return 0;
}
