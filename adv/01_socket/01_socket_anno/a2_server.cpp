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
  if (argc!=2) { // 如果不传入2个参数，则报错
    printf("Using:./server port\nExample:./server 5005\n\n"); return -1;
  }

  for(int i=0; i<argc; i++){
    printf(">> argv[%d]=%s\n", i, argv[i]);
  }
/*
>> argv[0]=./server
>> argv[1]=5000
*/


  // 第1步：创建服务端的socket。
  int listenfd;
  if ( (listenfd = socket(AF_INET,SOCK_STREAM,0))==-1) { perror("socket"); return -1; }

  printf(">> step1: listenfd=%d\n", listenfd);





  // 第2步：把服务端用于通信的地址和端口绑定到socket上。bind
  struct sockaddr_in servaddr;    // 服务端地址信息的数据结构。

  printf(">> step2: sizeof servaddr=%ld\n", sizeof servaddr); //16 字节

  memset(&servaddr, 0, sizeof(servaddr));//设置为0

  servaddr.sin_family = AF_INET;  // 协议族，在socket编程中只能是AF_INET。
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);          // 任意ip地址。
  //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); // 指定ip地址。

  servaddr.sin_port = htons(atoi(argv[1]));  // 指定通信端口。

  if (bind(listenfd,(struct sockaddr *)&servaddr, sizeof(servaddr)) != 0 )
  { perror("bind"); close(listenfd); return -1; }
 



  // 第3步：把socket设置为监听模式。listen
  //sleep(5); //放这里，则客户端无法立刻连接:connect: Connection refused。 
  // 需要等到服务端运行 listen 运行后，客户端才能连接
  if (listen(listenfd, 5) != 0 ) { perror("listen"); close(listenfd); return -1; }
  // 到这一步是阻塞的，等待客户端连接。客户端可以连接，然后等待服务端响应
  printf("[step3] after listen: block here\n");
  sleep(2);
 

 

  // 第4步：接受客户端的连接。 accept 会阻塞
  int  clientfd;                  // 客户端的socket。
  int  socklen=sizeof(struct sockaddr_in); // struct sockaddr_in的大小
  struct sockaddr_in clientaddr;  // 客户端的地址信息。
  printf("[step4] sizeof sockaddr_in=%ld, sockaddr_in=%ld\n", 
      sizeof(struct sockaddr_in), sizeof(struct sockaddr_in) );// 16 16

  clientfd=accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t*)&socklen);
  printf("客户端（%s:%d）已连接。\n",inet_ntoa(clientaddr.sin_addr), clientaddr.sin_port); //打印客户端的 IP:端口

  printf("[step4] accept 会阻塞，没有客户端连接就一直等待，客户端连接上才能看到这句话。 clientaddr.sin_family=%d\n", clientaddr.sin_family);



  // 第5步：与客户端通信，接收客户端发过来的报文后，回复ok。 recv/send, recv也会阻塞
  // 这里是主要的可操作区域
  char buffer[1024]; // 缓冲区
  while (1)
  {
    int iret;
    memset(buffer, 0, sizeof(buffer));

    if ( (iret=recv(clientfd, buffer, sizeof(buffer), 0))<=0) // 接收客户端的请求报文。
    {
       printf("[something wrong~, 可能客户端关闭了连接]iret=%d\n",iret); 
       break;  
    }
    printf("接收：%s\n",buffer);
 
    //准备向客户端发送的字符串
    //strcpy(buffer,"ok"); //方法1
    sprintf(buffer, "ok, receive %ld bytes from client", strlen(buffer)); //方法2

    if ( (iret=send(clientfd, buffer, strlen(buffer), 0))<=0) // 向客户端发送响应结果。
    { perror("send"); break; }

    printf("发送>：%s\n",buffer);
  }
 




  // 第6步：关闭socket，释放资源。 close
  close(listenfd); 
  close(clientfd);

  printf("[step6] Close\n");




  return 0;
}

/*
$ g++ -std=c++11 a2_server.cpp -o server
$ ./server 5000
*/