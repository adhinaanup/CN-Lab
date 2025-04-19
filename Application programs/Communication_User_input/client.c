#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
	int sockfd;
	struct sockaddr_in server;
	char buffer[1024];
	socklen_t len=sizeof(server);
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(8080);

	printf("Enter to send to server : ");
	fgets(buffer, sizeof(buffer), stdin);
	sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)&server,len);

	memset(buffer,0,strlen(buffer));	

	int n=recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&server,&len);
	printf("From server : %s",buffer);
	if(n<0)
	{
		perror("Failed");
	}
	buffer[n]='\0';
	close(sockfd);
	return 0;
}
