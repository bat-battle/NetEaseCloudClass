/*************************************************************************
	> File Name: ser.c
	> Author: battle
	> Mail: batbattle@163.com 
	> Created Time: 2018年06月17日 星期天 8时02分22秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>

#define PORT  5555
#define BACKLOG 10
#define MAXDATASIZE  2048
#define true 1
#define false 0

#if 0
默认情况下，socket的运行模式是：同步阻塞。
阻塞的函数有: accept、connect、send/write/writev/sendmsg、recv/read/readv/recvmsg
所以当调用以上阻塞函数时，一旦系统对应的资源没有就绪，当前执行线程的CPU就会被剥夺，
从而进入阻塞挂起状态，看着像程序‘卡死’了。

了解进程有哪些状态，可参考https://www.jianshu.com/c/934778e788cb

为了实现用户1和用户2与服务器的交互是相互完全独立的，即用户2发送数据不会因为用户1正在和
服务器传送一个很大文件（比如，电影）而进行无意义的等待。可以通过ioctl和fcntl设置一个
socket文件描述符为非阻塞。
#endif

int setnonblocking(int fd)                                                         
{                                                                                  
	/*
	   NAME
	   fcntl -- file control

	   SYNOPSIS
    #include <fcntl.h>

    int
    fcntl(int fildes, int cmd, ...);

    DESCRIPTION
    fcntl() provides for control over descriptors.  The argument fildes is a 
    descriptor to be operated on by cmd as follows:
    */ 
    int old_option = fcntl(fd, F_GETFL);                                           
    int new_option = old_option | O_NONBLOCK;                                      
    fcntl(fd, F_SETFL, new_option);                                                
    return old_option;                                                             
}   

int main(int argc, char *argv[])
{
    int listenfd;

    //创建一个socket描述符，此描述符仅是本主机上的一个普通文件描述符而已
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("listenfd=%d\n", listenfd);

    //定义一个结构体变量servaddr，用来记录给定的IP和port信息，为bind函数做准备
    struct sockaddr_in serveraddr;
    bzero(&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT); //把端口转化为网络字节序，即大端模式
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    //把“本地含义的描述符”绑定到一个IP和Port上，此时这个socket才具备对外连接的能力
    bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    //创建一个监听队列，用来保存用户的请求连接信息（ip、port、protocol)
    //把监听socket设置成非阻塞之后，accept函数在listen队列里取不到“新连接”时也不阻塞了，
    //但有新的连接到达，accept函数也能正常取到一个socket描述符，用户收发数据。
    //要提醒的是，在企业编程时，不会把监听socket设置成非阻塞。
    //企业百万并发往往都是采用IO复用函数+非阻塞机制实现，下次课程就会一起讨论
//    setnonblocking(listenfd);
    listen(listenfd, BACKLOG);

    printf("======bind and listen success,waiting for client's request======\n");
    //让操作系统回填client的连接信息（ip、port、protocol）
    struct sockaddr_in peeraddr;
    socklen_t peer_len = sizeof(peeraddr);
    int connfd;
    char buff[MAXDATASIZE];

    while(1)
    {
        //accept函数从listen函数维护的监听队列里取一个客户连接请求处理
        connfd = accept(listenfd, (struct sockaddr*)&peeraddr, &peer_len);
        //把新连接的socket描述符设置非阻塞之后，服务器就不会阻塞在recv调用
//        setnonblocking(connfd);
        printf("\n=====================客户端链接成功=====================\n");
        printf("IP = %s:PORT = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        memset(buff, '\0', MAXDATASIZE/sizeof (char));

        int recv_length = recv(connfd, buff, MAXDATASIZE/sizeof (char), 0);
        if(recv_length == 0)
        {
            printf("client has closed!\n");
                break;
        }
        printf("client say[%d]: ", recv_length);
        fputs(buff, stdout);

        char sendbuff[] = "您好，学习过程中遇到任何问题，可以加入QQ群：676593534，讨论交流哦！\n";
        send(connfd, sendbuff, strlen(sendbuff), 0);
        close(connfd);
    }
    close(listenfd);
    return 0;
}
