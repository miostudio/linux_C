#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define MAXLINE 4096

/*
fix1: 错误异常不能返回0
update: 循环发送消息，接收消息
*/

int main(int argc, char** argv){
    int   client_sockfd, len;
    char  recvline[4096], sendline[4096];
    struct sockaddr_in  servaddr; //服务器端网络地址结构体

    if( argc != 2){
        printf("usage: ./client <ipaddress>\n");
        return 1;
    }

    if( (client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr)); //数据初始化--清零
    servaddr.sin_family = AF_INET; //设置为IP通信
    servaddr.sin_port = htons(9000); //服务端端口号
    if( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){ //传入参数：服务器IP地址
        printf("inet_pton error for %s\n",argv[1]);
        return 1;
    }

	/*将套接字绑定到服务器的网络地址上*/
    if( connect(client_sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        return 1;
    }
	
	printf("connected to server\n");
	len=recv(client_sockfd,recvline,BUFSIZ,0);//接收服务器端信息
	recvline[len]='\0';
	printf("received:%s\n",recvline);
	
	/*循环的发送接收信息并打印接收信息（可以按需发送）--recv返回接收到的字节数，send返回发送的字节数*/
	while(1){
		printf("send msg to server(type quit to exit): \n");
		fgets(sendline, 4096, stdin);
		/*发送消息*/
		if( ( len=send(client_sockfd, sendline, strlen(sendline), 0) ) < 0){
			printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
			return 1;
		}
		
		if(!strcmp(sendline,"quit\n")){
			printf("quiting now ...\n");
			break;
		}
		
		/*接收消息*/
		len=recv(client_sockfd, recvline, BUFSIZ, 0);
		recvline[len]='\0';
		printf("received:%s\n",recvline);
		
	}
	
	/*关闭套接字*/
    close(client_sockfd);
    return 0;
}
