#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "main.h"
#include "net.h"

#define NET "ens33"
#define IP "224.21.21.70"
#define PORT 2170
#define MESS "ABCD"

int main(int argc, char **argv)
{
	char eth[40] = {0};
	strncpy(eth, NET, strlen(NET));

	char My_IP[40] = {0};
	strncpy(My_IP, IP, strlen(IP));

	char Mess[5] = {0};
	strncpy(Mess, MESS, strlen(MESS));
	
	
	char buff[5] = {0};
	strncpy(buff, MESS, strlen(MESS));

	Multicast_Send *server = new Multicast_Send(My_IP, PORT, eth, 8);
	
	while(1)
	{
		server->Send((unsigned char *)buff, 5);
		printf("%s\n", buff);
		sleep(1);
	}
	
	return 0;
}
