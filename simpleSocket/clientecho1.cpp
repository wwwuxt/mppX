#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define BUF_SIZE 100
int main() {
    // 创建socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // 向服务器(特点IP和端口)发送请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);

    char buf_send[BUF_SIZE] = {0};
    char buf_recv[BUF_SIZE] = {0};
    while(1){
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    
        // 获取用户输入的字符串并发送服务器
        printf("Input a string: ");
        scanf("%s", buf_send);
        write(sock, buf_send, strlen(buf_send));

        // 接收服务器传回的数据
        read(sock, buf_recv, BUF_SIZE);

        printf("Message from server: %s\n", buf_recv);

        memset(buf_send, 0, BUF_SIZE);
        memset(buf_recv, 0, BUF_SIZE);
        // 关闭socket
        close(sock);
    }
    return 0;
    
}
