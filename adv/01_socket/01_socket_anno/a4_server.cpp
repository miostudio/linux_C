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

/* How to run?
$ g++ -std=c++11 a4_server.cpp -o server
$ ./server 5000
*/

char* s_gets(char *st, int n);

// 初始化服务端的socket，port为通信端口
// 返回值：成功返回初始化的socket，失败返回-1。
int initServer(int port);


int main(int argc,char *argv[]) {
    if (argc!=2) { // 如果不传入2个参数，则报错
        printf("Using:./server port\nExample:./server 5005\n\n"); return -1;
    }

    //1新建 socket; 2.绑定端口号; 3.开始监听;
    int listenfd = initServer(atoi(argv[1]));
    if (listenfd<=0) { printf("服务端初始化失败，程序退出。\n"); return -1; }


    // 第4步：接受客户端的连接。 accept 会阻塞
    int  clientfd;                  // 客户端的socket。
    int  socklen=sizeof(struct sockaddr_in); // struct sockaddr_in的大小
    struct sockaddr_in clientaddr;  // 客户端的地址信息。
    printf("Server ready. Waiting for connection...\n");
    clientfd=accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t*)&socklen);
    if ( clientfd <= 0) { printf("服务端accept失败，程序退出。\n"); return -1; }
    printf("客户端（%s:%d）已连接。\n",inet_ntoa(clientaddr.sin_addr), clientaddr.sin_port); //打印客户端的 IP:端口



    // 第5步：与客户端通信，接收客户端发过来的报文后，回复ok。 recv/send, recv也会阻塞
    // 这里是主要的可操作区域
    char buffer[1024]; // 缓冲区

    // 接收消息，自动回复ok。
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (recv(clientfd, buffer, sizeof(buffer),0)<=0) break;
        printf("接收：%s\n", buffer);

        //准备向客户端发送的字符串
        strcpy(buffer,"ok"); //方法1
        //sprintf(buffer, "ok, receive %ld bytes from client", strlen(buffer)); //方法2
        if (send(clientfd, buffer, strlen(buffer), 0)<=0) break;
        printf("发送：%s\n",buffer);
    }


    // 手工输入回复消息
/*    while (1)  {
        int iret;
        memset(buffer, 0, sizeof(buffer));

        if ( (iret=recv(clientfd, buffer, sizeof(buffer), 0))<=0) // 接收客户端的请求报文。
        {
        printf("[something wrong~, 可能客户端关闭了连接]iret=%d\n",iret);  break;  
        }
        printf("接收：%s\n",buffer);

        //方法3：让用户输入
        printf("Please input your reply >> "); 
        s_gets(buffer, 1024);
        if ( (iret=send(clientfd, buffer, strlen(buffer), 0))<=0) // 向客户端发送响应结果。
        { perror("send2"); break; } //如果客户端退出，则这里会检查是否发送成功 send2: Success

        //printf("发送>：%s\n",buffer);
    }
 */


    printf("客户端已断开连接。\n");


    // 第6步：关闭socket，释放资源。 close
    close(listenfd); 
    close(clientfd);

    return 0;
}





// 初始化服务端的socket，port为通信端口
// 返回值：成功返回初始化的socket，失败返回-1。
int initServer(int port){
    // 第1步：创建服务端的socket。
    int listenfd;
    if ( (listenfd = socket(AF_INET,SOCK_STREAM,0))==-1) { perror("socket"); return -1; }


    // 第2步：把服务端用于通信的地址和端口绑定到socket上。bind
    struct sockaddr_in servaddr;    // 服务端地址信息的数据结构。
    memset(&servaddr, 0, sizeof(servaddr));//设置为0

    servaddr.sin_family = AF_INET;  // 协议族，在socket编程中只能是AF_INET。
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);          // 任意ip地址。
    //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); // 指定ip地址。

    servaddr.sin_port = htons(port);  // 指定通信端口。使用网络字节序

    if (bind(listenfd,(struct sockaddr *)&servaddr, sizeof(servaddr)) != 0 )
    { perror("bind"); close(listenfd); return -1; }


    // 第3步：把socket设置为监听模式。listen
    if (listen(listenfd, 5) != 0 ) { perror("listen"); close(listenfd); return -1; }

    return listenfd;
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

