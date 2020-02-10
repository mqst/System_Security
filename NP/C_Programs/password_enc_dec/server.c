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
saddr.sin_port=3004;

server=socket(PF_INET,SOCK_STREAM,0);

bind(server,(struct sockaddr *)&saddr, sizeof(saddr));

printf("%d",listen(server,1));
char d1[30],d2[10],buf[30];
char d3[30];
int i;
char pass[]="1234";
int len=sizeof(caddr);
while(1)
{
client=accept(server,(struct sockaddr*)&caddr,&len);
recv(client,d1,10,0);
printf("Encrypted password: %d\n",d1);
//recv(client,d2,10,0);
for(i=0;d1[i]!='\0';i++)
{
d1[i]=d1[i]-d1[i+1];
}
if(strcmp(pass,d1) == 0){
sprintf(d1,"CORRECT password\n");
send(client,d1,30,0);

}
else{	
sprintf(d1,"Wrong password\n");
send(client,d1,30,0);

}
}


}
