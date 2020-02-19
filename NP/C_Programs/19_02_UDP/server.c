#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
int client, server;
struct sockaddr_in saddr,caddr;

saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr.sin_family=AF_INET;
saddr.sin_port=1234;
server=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
bind(server,(struct sockaddr*)&saddr,sizeof(saddr));
int len=sizeof(caddr);

char d1[30];
recvfrom(server,d1,30,0,(struct sockaddr*)&caddr,&len);
sendto(server,d1,30,0,(struct sockaddr*)&caddr,len);
printf("%s",d1);
}
