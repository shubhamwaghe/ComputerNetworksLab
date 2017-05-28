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
	
	
	
	length = sizeof(sa);
	fd1 = accept(sockfd, (struct sockaddr *) &ta1, &length);
	fd2 = accept(sockfd, (struct sockaddr *) &ta2, &length);
	
	int n1[10];
	int n2[10];

	recv(fd1, &n1, 4*10, 0);
	recv(fd2, &n2, 4*10, 0);

	send(fd1, &n2, 4*10, 0);
	send(fd2, &n1, 4*10, 0);
	 
}

























