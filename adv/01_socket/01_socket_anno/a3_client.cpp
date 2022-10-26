#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// v3 双方聊天版 client

//C primer plus 中最高频的函数，读取一行字符串到st指针，最长为n，末尾为\0
char* s_gets(char *st, int n){
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin); //读取一行，末尾可能会有\n
    if(ret_val){
        find = strchr(st, '\n'); //找到 \n 的位置下标
        if(find){
            *find = '\0'; //替换为字符串结尾
        }else{
            while( getchar() != '\n') //忽略掉这一行其余的输入：应该是超过 int n个时起作用
                continue;
        }
    }
    return ret_val;
}


int main(int argc,char *argv[])
{
  if (argc!=3) { //必须至少3个参数
    printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n"); 
    return -1;
  }

  // 第1步：创建客户端的socket。
  int sockfd;
  if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0))==-1) { perror("socket"); return -1; }

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
  int counter=0;

    while(true){
        int iret;
        memset(buffer, 0, sizeof(buffer));
        printf("Please input your msg %d(exit with 'byebye') >> ", ++counter);
        s_gets(buffer, 1024);

        if ( (iret=send(sockfd,buffer,strlen(buffer),0))<=0) // 向服务端发送请求报文。
        { perror("send"); break; }
        //printf("发送>：%s\n", buffer);

        //如果发送的 byebye 则结束会话
        if( strcmp(buffer, "byebye")==0){
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        if ( (iret=recv(sockfd, buffer, sizeof(buffer),0))<=0) // 接收服务端的回应报文。
        {
        printf("iret=%d\n",iret); break;
        }
        printf("接收：%s\n",buffer);
    }

/*
  for (int ii=0; ii<3; ii++)
  {
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
 */




  // 第4步：关闭socket，释放资源。close
  close(sockfd);

  return 0;
}

/*
$ g++ -std=c++11 a3_client.cpp -o client
$ ./client 127.0.0.1 5000
*/