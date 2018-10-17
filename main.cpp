#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "main.h"
#include "net.h"

#define NET "ens33"
#define PORT 2170
#define MESS "ABCD"
#define IP "224.21.21.70"

using namespace std;

int main(int argc, char **argv)
{
	string eth = NET;
	string My_IP = IP;
	
	Multicast_Recv  *client = new Multicast_Recv(My_IP, PORT, eth, 320*1024, 0);

	char buff[5] = {0};
	
	while(1)
	{
		client->Recv((unsigned char*)buff, 5);
		printf("%s\n", buff);
	}
	
	return 0;
}
