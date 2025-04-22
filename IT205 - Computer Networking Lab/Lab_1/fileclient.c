//file transfer client program:fileclient.cc

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>
#define SERV_PORT 5576
int main()
{
int i,j;
ssize_t n;
char filename[80],recvline[80];
struct sockaddr_in servaddr;
int sockfd;
sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

printf("\nenter the file name\n");
scanf("%s",filename);
write(sockfd,filename,sizeof(filename));
printf("\n data from server: \n");

while(read(sockfd,recvline,80)!=0)
{
fputs(recvline,stdout);
}
close(sockfd);

}

