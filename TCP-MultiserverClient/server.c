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
	
	int n1, n2;
	printf("Enter first number: ");
	scanf("%d", &n1);
	printf("Enter second number: ");
	scanf("%d", &n2);

	length = sizeof(sa);
	fd1 = accept(sockfd, (struct sockaddr *) &ta1, &length);
	fd2 = accept(sockfd, (struct sockaddr *) &ta2, &length);
	
	send(fd1, &n1, 4, 0);
	send(fd2, &n2, 4, 0);

	int c1, c2;
	recv(fd1, &c1, 4, 0);
	recv(fd2, &c2, 4, 0);
	printf("Sums sent: %d and %d\n", c1, c2);
	 
}

























