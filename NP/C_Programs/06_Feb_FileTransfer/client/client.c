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
saddr.sin_port=2222;

char d1[80],fname[30];
FILE *fp;
client=socket(PF_INET,SOCK_STREAM,0);

connect(client,(struct sockaddr *)&saddr,sizeof(saddr));

printf("#### FTP Server #### \n");
printf("Enter the name of the file: \n");
scanf("%s",fname);
send(client,fname,30,0);
fp=fopen(fname,"r");
while (!feof(fp)){
fgets(d1,80,fp);
send(client,d1,80,0);
}
sprintf(d1,"end");
send(client,d1,80,0);
fclose(fp);

}
