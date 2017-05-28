#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
	
	int i, sockfd, sockfd2, j;
	char s[50];
	struct sockaddr_in sa, sb;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");
	sa.sin_port = 6001;

	/*
	printf("Give server address and port number: ");
	scanf("%s %d", s, &a); 
	sa.sin_addr.s_addr = inet_addr(s);
	sa.sin_port = a;
	*/

	i = connect(sockfd, (struct sockaddr *) &sa, sizeof(sa));
	
	printf("socketfd, i: %d %d\n", sockfd, i);

	int r; // Client number	
	recv(sockfd, &r, 4, 0);

	int p, q;
	
	if(r == 1) {
		printf("Enter a number: ");
		scanf("%d", &p);
		send(sockfd, &p, 4, 0);
	} else {
		recv(sockfd, &q, 4, 0);
		printf("Recived number: %d\n", q);
	}
}























