#ifndef NET_H_
#define NET_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/tcp.h>

class TCP_client{
	private:
		//欲连接的服务器IP
		char IP[40];
		//欲连接的服务端口
		int port;
		//地址结构体
		struct sockaddr_in addr;
		//通信网卡
		char eth[40];
		//连接成功后的文件描述符
		int sockfd;
	public:
		TCP_client(char *IP, int port, char *eth);
		~TCP_client();
		char *Get_Self_IP();
		void Set_Sock_Noblock();
		int Send(unsigned char *send_buffer, int len);
		int Recv(unsigned char *recv_buffer, int len);
};

class TCP_Server_Listen{
	private:
		int reuse;
		int port;
		int backlog;
		struct sockaddr_in addr;
		char eth[40];
		int sockfd;
	public:
		TCP_Server_Listen(int Port, char *eth);
		~TCP_Server_Listen();
		int Get_Listen_Fd();
		char *Get_Self_IP();
};

class TCP_Server_Accept{
	private:
		int listen_fd;
		int sockfd;
		
		struct sockaddr_in addr;
		socklen_t len;
	public:
		TCP_Server_Accept(int listen_fd);
		~TCP_Server_Accept();
		void Set_Sock_Noblock();
		int Send(unsigned char *send_buffer, int len);
		int Recv(unsigned char *recv_buffer, int len);
};

class UDP_Server{
	private:
		int reuse;
		int port;
		struct sockaddr_in addr;
		socklen_t addrlen;
		char eth[40];
		int sockfd;
	public:
		UDP_Server(int port, char *eth);
		~UDP_Server();
		int Recv(unsigned char *recv_buffer, int len);
		char *Get_Self_IP();
};

class UDP_Client{
	private:
		char IP[40];
		int port;
		struct sockaddr_in addr;
		socklen_t addrlen;
		char eth[40];
		int sockfd;
	public:
		UDP_Client(char *IP, int port, char *eth);
		~UDP_Client();
		int Send(unsigned char *send_buffer, int len);
		char *Get_Self_IP();
};

class Multicast_Send{
	private:
		int ttl;
		char IP[40];
		int port;
		struct sockaddr_in addr;
		socklen_t addrlen;
		char eth[40];
		int sockfd;
	public:
		Multicast_Send(char *IP, int port, char *eth, int ttl);
		~Multicast_Send();
		int Send(unsigned char *send_buffer, int len);
		char *Get_Self_IP();
};

class Multicast_Recv{
	private:
		int reuse;
		int loop;
		int buffersize;
		char IP[40];
		int port;
		struct sockaddr_in addr;
		socklen_t addrlen;
		char eth[40];
		int sockfd;
	public:
		Multicast_Recv(char *IP, int port, char *eth, int buffersize, int loop);
		~Multicast_Recv();
		int Recv(unsigned char *recv_buffer, int len);
		char *Get_Self_IP();
};

void Net_print(unsigned char *buff, int len);

#endif 
