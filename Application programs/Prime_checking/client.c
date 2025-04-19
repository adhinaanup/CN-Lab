#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

int main()
{
	int sockfd;
	struct sockaddr_in server;
	char buffer[1024];
	socklen_t len=sizeof(server);

	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(8080);

	printf("Enter data : ");
	scanf("%s",buffer);
	sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)&server,len);

	memset(buffer,0,sizeof(buffer));
		
	int n=recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&server,&len);
	buffer[n]='\0';

	printf("%s",buffer);
		
		
	
	close(sockfd);
	return 0;
}
