#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
	int sockfd;
	struct sockaddr_in server,client;
	char buffer[1024];
	socklen_t len=sizeof(client);
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(8080);

	bind(sockfd,(struct sockaddr *)&server,sizeof(server));

	int n=recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&client,&len);
	printf("From client : %s\n",buffer);
	if(n<0)
	{
		perror("Failed");
	}
	
	memset(buffer,0,strlen(buffer));
	printf("Enter to send to client : ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[n]='\0';
	sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)&client,len);

	close(sockfd);
	return 0;
}
