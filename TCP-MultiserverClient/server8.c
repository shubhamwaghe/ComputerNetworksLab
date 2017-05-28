#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
	
	int sockfd, fd1, fd2, length, i, a, b, j;
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
	
	printf("Enter 10 pair numbers: ");
	int x,y;
	for (j=0; j<10; j++) {
		scanf("%d %d", &x, &y);
		if (x == 1) {
			send(fd1, &y, 4, 0);
		} else if (x == 2){
			send(fd2, &y, 4, 0);
		}
	}

	int end = -1;
	send(fd1, &end, 4, 0);
	send(fd2, &end, 4, 0);

	int n1, n2;
	recv(fd1, &n1, 4, 0);
	recv(fd2, &n2, 4, 0);
	printf("Received numbers: %d and %d\n", n1, n2);
	 
}

























