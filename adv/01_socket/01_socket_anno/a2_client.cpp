#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
int main(int argc,char *argv[])
{
  if (argc!=3) { //必须至少3个参数
    printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n"); 
    return -1;
  }
 
   for(int i=0; i<argc; i++){
    printf(">> argv[%d]=%s\n", i, argv[i]);
  }
/*
>> argv[0]=./client
>> argv[1]=127.0.0.1
>> argv[2]=5000
*/


  // 第1步：创建客户端的socket。
  int sockfd;
  if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0))==-1) { perror("socket"); return -1; }

  printf("[step1] sockfd=%d\n", sockfd);




  // 第2步：向服务器发起连接请求。connect()
  struct hostent* h;
  if ( (h = gethostbyname(argv[1])) == 0 )   // 指定服务端的ip地址。
  { printf("gethostbyname failed.\n"); close(sockfd); return -1; }
  struct sockaddr_in servaddr;
  memset(&servaddr,0,sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2])); // 指定服务端的通信端口。
  memcpy(&servaddr.sin_addr, h->h_addr, h->h_length); //在内存中，按位复制IP地址

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)  // 向服务端发起连接清求。
  { perror("connect"); close(sockfd); return -1; }
 
 




  // 第3步：与服务端通信，发送一个报文后等待回复，然后再发下一个报文。 send/recv, recv也会阻塞
  char buffer[1024];

  for (int ii=0; ii<3; ii++)
  {
    sleep(2); //这里休息2秒
    int iret;
    memset(buffer,0,sizeof(buffer));

    sprintf(buffer,"这是第%d个文本信息，编号%03d。",ii+1,ii+1);
    if ( (iret=send(sockfd,buffer,strlen(buffer),0))<=0) // 向服务端发送请求报文。
    { perror("send"); break; }
    printf("发送>：%s\n",buffer);
 
    memset(buffer,0,sizeof(buffer));
    if ( (iret=recv(sockfd, buffer, sizeof(buffer),0))<=0) // 接收服务端的回应报文。
    {
       printf("iret=%d\n",iret); break;
    }
    printf("接收：%s\n",buffer);
  }
 




  // 第4步：关闭socket，释放资源。close
  printf("[step4] 客户端将在5s后关闭\n");
  sleep(5);
  close(sockfd);

  return 0;
}

/*
$ g++ -std=c++11 a2_client.cpp -o client
$ ./client 127.0.0.1 5000
*/