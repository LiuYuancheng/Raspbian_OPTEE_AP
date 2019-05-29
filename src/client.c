// Write CPP code here 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define MAX 80 
#define PORT 5005 
#define SA struct sockaddr 
void func(int sockfd) 
{
	char buff[MAX]; 
	int n; 
	for (;;) {
		printf("wait for server response\n");
		bzero(buff, sizeof(buff)); 
		printf("Enter the string : \n"); 
		n = 0; 
		buff[0] = 'F';
		buff[1] = 'D';
		sleep(1);
		write(sockfd, buff, sizeof(buff)); 
		bzero(buff, sizeof(buff)); 
		read(sockfd, buff, sizeof(buff));
		printf("From Server : %d", atoi(buff)); 
	} 
} 

int main() 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 
	
	printf("sss\n");
	// function for chat 
	func(sockfd); 
	printf("xxxxxxxxxxx");
	// close the socket 
	close(sockfd); 
} 

