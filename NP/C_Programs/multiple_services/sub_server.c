#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
int client, server;
struct sockaddr_in saddr,caddr;

saddr.sin_addr.s_addr=inet_addr("192.168.100.19");
saddr.sin_family=AF_INET;
saddr.sin_port=2222;

server=socket(PF_INET,SOCK_STREAM,0);

bind(server,(struct sockaddr *)&saddr, sizeof(saddr));

//if (listen(server, 1) < 0) 
  // { 
    //    perror("listen"); 
     //   exit(EXIT_FAILURE); 
    //} 
printf("%d",listen(server,1));
char d1[10],d2[10],buf[30];
int d3;
int len=sizeof(caddr);
while(1)
{
	client=accept(server,(struct sockaddr*)&caddr,&len);
	recv(client,d1,10,0);
	recv(client,d2,10,0);
	d3=atoi(d1)-atoi(d2);
	sprintf(buf,"Subtraction = %d\n",d3);
	send(client,buf,30,0);
}

}
