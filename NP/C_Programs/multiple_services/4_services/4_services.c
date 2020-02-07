#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>
int main()
{
int client, server1,server2,server3,server4;
struct sockaddr_in saddr1,saddr2,saddr3,saddr4,caddr;

//============================
saddr1.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr1.sin_family=AF_INET;
saddr1.sin_port=5555;
server1=socket(PF_INET,SOCK_STREAM,0);
bind(server1,(struct sockaddr *)&saddr1, sizeof(saddr1));
printf("%d",listen(server1,2));
//============================
saddr2.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr2.sin_family=AF_INET;
saddr2.sin_port=2222;
server2=socket(PF_INET,SOCK_STREAM,0);
bind(server2,(struct sockaddr *)&saddr2, sizeof(saddr2));
printf("%d",listen(server2,2));
//============================
saddr3.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr3.sin_family=AF_INET;
saddr3.sin_port=1113;
server3=socket(PF_INET,SOCK_STREAM,0);
bind(server3,(struct sockaddr *)&saddr3, sizeof(saddr3));
printf("%d",listen(server3,1));
//============================
saddr4.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr4.sin_family=AF_INET;
saddr4.sin_port=1114;
server4=socket(PF_INET,SOCK_STREAM,0);
bind(server4,(struct sockaddr *)&saddr4, sizeof(saddr4));
printf("%d",listen(server4,1));
//============================

fd_set rfds;
FD_ZERO(&rfds);
int sock;
int len=sizeof(caddr);
char d1[100],d2[100],buf[100],choice[10];
int d3;

while(1)
{
FD_SET(server1,&rfds);
FD_SET(server2,&rfds);
FD_SET(server3,&rfds);
FD_SET(server4,&rfds);
select(server4+1,&rfds,NULL,NULL,(struct timeval *)0);

//============================
if(FD_ISSET(server1,&rfds)){
sock=accept(server1,(struct sockaddr *)&caddr,&len);
recv(sock,d1,100,0);
recv(sock,d2,100,0);
d3=atoi(d1)+atoi(d2);
sprintf(buf,"Result of Addition = %d\n",d3);
send(sock,buf,100,0);
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
//============================
if(FD_ISSET(server3,&rfds)){
sock=accept(server3,(struct sockaddr *)&caddr,&len);

close(sock);
}
//============================
if(FD_ISSET(server4,&rfds)){
sock=accept(server4,(struct sockaddr *)&caddr,&len);

close(sock);
}
//============================
}
}
