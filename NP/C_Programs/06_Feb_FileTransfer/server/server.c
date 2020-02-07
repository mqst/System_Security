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
saddr.sin_port=2222;

server=socket(PF_INET,SOCK_STREAM,0);

bind(server,(struct sockaddr *)&saddr, sizeof(saddr));

printf("%d",listen(server,1));
char d1[80],fname[30];
FILE *fp;
int len=sizeof(caddr);
client=accept(server,(struct sockaddr*)&caddr,&len);
recv(client,fname,30,0);
fp=fopen(fname,"w");
while(1){
	recv(client,d1,80,0);
	if(strcmp(d1,"end")==0)
	break;
	else
	fprintf(fp,"%s",d1);

}
fclose(fp);

}
