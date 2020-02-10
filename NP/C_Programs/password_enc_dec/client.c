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
saddr.sin_port=3004;

char d1[30],d2[10],d3[30];
int i;
client=socket(PF_INET,SOCK_STREAM,0);

connect(client,(struct sockaddr *)&saddr,sizeof(saddr));

printf("#### Encryption/Decryption of password!  #### \n");

printf("Enter the password: \n");
scanf("%s",d1);


//printf("Enter second number: \n");
//scanf("%s",d2);

for(i=0;d1[i]!='\0';i++){
d1[i]=d1[i]+d1[i+1];
}
send(client,d1,30,0);
//send(client,d2,10,0);

recv(client,d3,30,0);
printf(d3);

}


