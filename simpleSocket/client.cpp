#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main() {
    // 创建socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // 向服务器(特点IP和端口)发送请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    
    // 读取服务器传回的数据
    char buffer[40];
    read(sock, buffer, sizeof(buffer)-1);

    printf("Message from server: %s\n", buffer);


    // 关闭socket
    close(sock);

    return 0;
    
}
