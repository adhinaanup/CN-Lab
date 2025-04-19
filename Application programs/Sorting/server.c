#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int main()
{
	int newsock,sockfd;
	struct sockaddr_in server,client;
	char buffer[1024];
	socklen_t len=sizeof(client);

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(8085);

	bind(sockfd,(struct sockaddr *)&server,sizeof(server));

	listen(sockfd,5);

	printf("Establishing connection with client....\n");
	
	newsock=accept(sockfd,(struct sockaddr *)&client,&len);
	int n=read(newsock,buffer,sizeof(buffer)-1);
	buffer[n]='\0';
	printf("%s\n",buffer);
	send(newsock,"Hello",5,0);

	int no[50],i=0;
	send(newsock,"Hello",5,0);
	char *token=strtok(buffer," ");	
	while(token!=NULL)
	{
		no[i++]=atoi(token);
		token=strtok(NULL," ");
	}

	for(int k=0;k<i-1;k++)
	{
		for(int j=0;j<i-k-1;j++)
		{
			if(no[j]>no[j+1])
			{
				int temp=no[j];
				no[j]=no[j+1];
				no[j+1]=temp;
			}
		}
	}
	printf("\nSorted list : \n");
	for(int j=0;j<i;j++)
	{
		printf("%d  ",no[j]);
	}
	
	

	close(newsock);
	close(sockfd);
	return 0;
}
