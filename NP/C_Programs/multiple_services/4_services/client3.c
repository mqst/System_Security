#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
int client;
struct sockaddr_in saddr;

saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
saddr.sin_family=AF_INET;
saddr.sin_port=5555;

char d1[100],d2[100],d3[100],choice[10];
client=socket(PF_INET,SOCK_STREAM,0);

connect(client,(struct sockaddr *)&saddr,sizeof(saddr));

printf("#### Print Addition of two numbers #### \n");

printf("Enter first number: \n");
scanf("%s",d1);
printf("Enter second number: \n");
scanf("%s",d2);
send(client,d1,100,0);
send(client,d2,100,0);
//recv(client,d3,100,0);
//printf("%s",d3);
//scanf("%s",choice);
//send(client,choice,10,0);
recv(client,d3,100,0);
printf("%s",d3);


}
