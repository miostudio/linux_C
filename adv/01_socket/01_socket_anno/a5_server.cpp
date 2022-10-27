#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// v3 双方聊天版 server
// v4 封装为函数
/* v5 封装为 类； 删了手工回复代码
    方法名用大写开头，是因为用小写会报错，可能是无法区分类外的重名函数, :: 呢？没试过
    类封装了复杂性，类使用者根本不需要知道 socket 变量。
*/

/* How to run?
$ g++ -std=c++11 a5_server.cpp -o server
$ ./server 5000
*/

char* s_gets(char *st, int n);

class SocketServer{
  int m_listenfd;   // 服务端用于监听的socket
  int m_clientfd;   // 客户端连上来的socket
public:
  SocketServer();
 
  bool InitServer(int port);  // 初始化服务端
 
  bool Accept();  // 等待客户端的连接
 
  // 向对端发送报文
  int  Send(const void *buf,const int buflen);
  // 接收对端的报文
  int  Recv(void *buf,const int buflen);
 
 ~SocketServer();
};




int main(int argc,char *argv[]) {
    printf("v5.1\t");
    if (argc!=2) { // 如果不传入2个参数，则报错
        printf("Using:./server port\nExample:./server 5005\n\n"); return -1;
    }

    //1新建 socket; 2.绑定端口号; 3.开始监听;
    SocketServer server;
    if (server.InitServer(atoi(argv[1])) == false)
    { printf("server.InitServer(%d) failed,exit...\n", atoi(argv[1])); return -1; }


    // 第4步：接受客户端的连接。 accept 会阻塞
    printf("Server ready. Waiting for connection...\n");
    if (server.Accept() == false) { printf("server.Accept() failed,exit...\n"); return -1; }

    printf("客户端已连接。\n");
    //printf("客户端（%s:%d）已连接。\n",inet_ntoa(clientaddr.sin_addr), clientaddr.sin_port); //打印客户端的 IP:端口



    // 第5步：与客户端通信，接收客户端发过来的报文后，回复ok。 recv/send, recv也会阻塞
    char buffer[1024]; // 缓冲区

    // 接收消息，自动回复ok。
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (server.Recv(buffer, sizeof(buffer))<=0) break;
        printf("接收：%s\n", buffer);

        //准备向客户端发送的字符串
        strcpy(buffer,"ok"); //方法1
        //sprintf(buffer, "ok, receive %ld bytes from client", strlen(buffer)); //方法2
        if (server.Send(buffer, strlen(buffer))<=0) break;
        printf("发送：%s\n",buffer);
    }

    printf("客户端已断开连接。\n");


    // 第6步：关闭socket，释放资源。 close
    //析构函数执行

    return 0;
}


//========= 类 实现部分
SocketServer::SocketServer(){
  // 构造函数初始化socket
  m_listenfd=m_clientfd=0;
}
 
SocketServer::~SocketServer() {
  if (m_listenfd!=0) close(m_listenfd);  // 析构函数关闭socket
  if (m_clientfd!=0) close(m_clientfd);  // 析构函数关闭socket
  printf("~Server 析构函数, close 2 sockets on server: done!\n");
}



// 初始化服务端的socket，port为通信端口
// 返回值：成功返回初始化的socket，失败返回-1。
bool SocketServer::InitServer(int port){
    // 第1步：创建服务端的socket。
    if ( (m_listenfd = socket(AF_INET,SOCK_STREAM,0))==-1) { perror("socket"); return -1; }

    // 第2步：把服务端用于通信的地址和端口绑定到socket上。bind
    struct sockaddr_in servaddr;    // 服务端地址信息的数据结构。
    memset(&servaddr, 0, sizeof(servaddr));//设置为0

    servaddr.sin_family = AF_INET;  // 协议族，在socket编程中只能是AF_INET。
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);          // 本主机的任意ip地址。
    //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); // 指定ip地址。

    servaddr.sin_port = htons(port);  // 指定通信端口。使用网络字节序

    if (bind(m_listenfd,(struct sockaddr *)&servaddr, sizeof(servaddr)) != 0 )
    { perror("bind"); close(m_listenfd); m_listenfd=0; return false; }

    // 第3步：把socket设置为监听模式。listen
    if (listen(m_listenfd, 5) != 0 ) { perror("listen"); close(m_listenfd); m_listenfd=0; return false; }

    return true;
}

// 接受客户端连接
bool SocketServer::Accept() {
  if ( (m_clientfd = accept(m_listenfd, 0, 0)) <= 0) return false;
  return true;
}

//发送消息
int SocketServer::Send(const void *buf, const int buflen) {
  return send(m_clientfd, buf, buflen, 0);
}

//接收消息
int SocketServer::Recv(void *buf, const int buflen) {
  return recv(m_clientfd, buf, buflen, 0);
}




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

