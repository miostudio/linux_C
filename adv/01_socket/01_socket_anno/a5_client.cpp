#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// v3 双方聊天版 client
// v4 封装为 函数
/* v5 封装为 类； 删了手工回复代码
    方法名用大写开头，是因为用小写会报错，可能是无法区分类外的重名函数, :: 呢？没试过
    类封装了复杂性，类使用者根本不需要知道 socket 变量。
*/

/*
$ g++ -std=c++11 a5_client.cpp -o client
$ ./client 127.0.0.1 5000
*/

//读取一行字符串，保存在st中，长度为n
char* s_gets(char *st, int n);

// TCP客户端连服务端的函数, serverIP-服务端ip，port通信端口
int connectToServer(const char *serverIP, const int port);

// 客户端
class SocketClient{
    int m_socketfd;
public:
    SocketClient();

    //向服务器发起连接：IP和端口号
    bool ConnectToServer(const char *serverIP, const int port);
    //发送
    int Send(const void *buf,const int buflen);
    //接收
    int Recv(void *buf, const int buflen);

    ~SocketClient();
};





int main(int argc,char *argv[]) {
    if (argc!=3) { //必须至少3个参数
        printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n"); 
        return -1;
    }

    SocketClient client;
    // 第1步: 创建socket; 
    // 第2步: 连接服务器：IP和端口号
    if(client.ConnectToServer( argv[1], atoi(argv[2]) )==false){
        printf("连接服务器失败，程序退出。\n"); return -1; 
    }

    // 第3步：与服务端通信，发送一个报文后等待回复，然后再发下一个报文。 send/recv, recv也会阻塞
    char buffer[1024];

    // 自动发送消息模式
    for (int ii=0; ii<3; ii++) {
        memset(buffer,0,sizeof(buffer));
        sprintf(buffer,"这是第%d个文本信息，编号%03d。",ii+1,ii+1);
        if ( (client.Send(buffer, strlen(buffer) ) ) <= 0 ) // 向服务端发送请求报文。
        { perror("send"); break; }
        printf("发送>：%s\n",buffer);

        memset(buffer,0,sizeof(buffer));
        if ( (client.Recv(buffer, sizeof(buffer))) <= 0 ) { break; }// 接收服务端的回应报文
        printf("接收：%s\n",buffer);
    }


    // 第4步：关闭socket，释放资源。close
    // 类会自动析构

    return 0;
}




// ============== 类 实现部分
SocketClient::SocketClient(){
    m_socketfd=0; //构造初始化
}

SocketClient::~SocketClient(){
    if(m_socketfd!=0) close(m_socketfd); //析构函数关闭m_sockfd
    printf("~ Client 析构函数, close client socket: done!\n");
}


// 客户端连服务端的函数，serverIP-服务端ip，port通信端口
// 返回值：成功返回已连接socket，失败返回-1。
bool SocketClient::ConnectToServer(const char *serverIP, const int port){
    // 第1步：创建客户端的socket
    if ( (m_socketfd  = socket(AF_INET, SOCK_STREAM, 0))==-1) { perror("socket"); return false; }


    // 第2步：向服务器发起连接请求。connect()
    struct hostent* h;
    if ( (h = gethostbyname(serverIP)) == 0 )   // 指定服务端的ip地址。
    { printf("gethostbyname failed.\n"); close(m_socketfd); return false; }

    // 把服务器的地址和端口转换为数据结构
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port); // 指定服务端的通信端口。
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length); //在内存中，按位复制IP地址

    // 向服务器发起连接请求
    if (connect(m_socketfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)  // 向服务端发起连接清求。
    { perror("connect"); close(m_socketfd); return false; }

    return true;
}

int SocketClient::Send(const void *buf, const int buflen) {
  return send(m_socketfd, buf, buflen, 0);
}
 
int SocketClient::Recv(void *buf, const int buflen) {
  return recv(m_socketfd,buf,buflen,0);
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
