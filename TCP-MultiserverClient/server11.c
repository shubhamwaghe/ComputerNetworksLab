#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
	
	int sockfd, fd1, fd2, length, i, a, b, j;
	struct sockaddr_in sa, sb, ta1, ta2;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;
	// sa.sin_port = 6001;

	printf("Give self port number: ");
	scanf("%d", &sa.sin_port);
	
	i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
	printf("socketfd, i: %d %d\n", sockfd, i);
	listen(sockfd, 5);
	

	length = sizeof(sa);
	fd1 = accept(sockfd, (struct sockaddr *) &ta1, &length);

	int r;
	recv(fd1, &r, 4, 0);
	printf("Received number: %d\n", r);
	
	 
}

























