#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
	
	int sockfd, fd1, fd2, length, i, a, b;
	struct sockaddr_in sa, ta1, ta2;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;
	sa.sin_port = 6001;

	// printf("Give self port number: ");
	// scanf("%d", &sa.sin_port);
	
	i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
	printf("socketfd, i: %d %d\n", sockfd, i);
	listen(sockfd, 5);
	
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	
	length = sizeof(sa);
	fd1 = accept(sockfd, (struct sockaddr *) &ta1, &length);
	fd2 = accept(sockfd, (struct sockaddr *) &ta2, &length);
	
	send(fd1, &n, 4, 0);
	int d1, d2;
	recv(fd1, &d1, 4, 0);
	printf("Received number: %d\n", d1);
	d1 = d1 + 10;

	send(fd2, &d1, 4, 0);
	recv(fd2, &d2, 4, 0);
	printf("Received number: %d\n", d2);
	 
}

























