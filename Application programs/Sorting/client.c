#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
	int sockfd;
	struct sockaddr_in server;
	char buffer[1024]="6 7 4 8 9 1 0 4 8 1 5 7";
	char response[1024];

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(8085);
	printf("Connecting the server....\n");

	connect(sockfd,(struct sockaddr *)&server,sizeof(server));
	printf("Connected...\n");

	send(sockfd,buffer,strlen(buffer),0);
	
	int n=read(sockfd,response,sizeof(response));
	buffer[n]='\0';
	//printf("%s\n",buffer);

	
	
	close(sockfd);
	return 0;
}
