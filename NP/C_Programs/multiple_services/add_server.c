#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>
int main()
{
int client, server1,server2,server3,server4;
struct sockaddr_in saddr1,saddr2,caddr;


//============================
saddr1.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr1.sin_family=AF_INET;
saddr1.sin_port=1111;
server1=socket(PF_INET,SOCK_STREAM,0);
bind(server1,(struct sockaddr *)&saddr1, sizeof(saddr1));
printf("%d",listen(server1,1));
//============================
saddr2.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr2.sin_family=AF_INET;
saddr2.sin_port=1112;
server2=socket(PF_INET,SOCK_STREAM,0);
bind(server2,(struct sockaddr *)&saddr2, sizeof(saddr2));
printf("%d",listen(server2,1));
//============================


fd_set rfds;
FD_ZERO(&rfds);
int sock;
int len=sizeof(caddr);
char d1[10],d2[10],buf[100],choice[10];
int d3;


while(1)
{
FD_SET(server1,&rfds);
FD_SET(server2,&rfds);
select(server2+1,&rfds,NULL,NULL,(struct timeval *)0);


//============================
if(FD_ISSET(server1,&rfds)){
sock=accept(server1,(struct sockaddr *)&caddr,&len);
recv(sock,d1,30,0);
send(sock,d1,30,0);
close(sock);
}
//============================
if(FD_ISSET(server2,&rfds)){
sock=accept(server2,(struct sockaddr *)&caddr,&len);
time_t t;
time(&t);
sprintf(buf,"\nCurrent date and time: %s", ctime(&t));
send(sock,buf,100,0);
close(sock);
}



}
}
