#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
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
	buffer[n]='\0';
	int no=atoi(buffer);
	//printf("%d",no);
	int flag=0;
	if(no<=1)
	{
		flag=1;
	}
	else if(no==2)
	{
		flag=0;
	}
	else
	{
		for(int i=2;i<=no/2;i++)
		{
			if(no%i==0)
			{
				flag=1;
				break;
			}
		}
	}
	if(!flag)
	{
		printf("%d is prime",no);
		sendto(sockfd,"Prime",5,0,(struct sockaddr *)&client,len);

	}
	else
	{
		printf("%d is not prime",no);
		sendto(sockfd,"Not Prime",9,0,(struct sockaddr *)&client,len);
	}

	
	memset(buffer,0,sizeof(buffer));	
	
		
	close(sockfd);
	return 0;
}
