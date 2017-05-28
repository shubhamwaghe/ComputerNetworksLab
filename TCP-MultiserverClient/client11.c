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
	// sa.sin_port = 6001;

	sockfd2 = socket(AF_INET, SOCK_STREAM, 0);
	sb.sin_family = AF_INET;
	sb.sin_addr.s_addr = inet_addr("127.0.0.1");
	// sb.sin_port = 6002;

	int p1, p2;
	printf("Enter port number of servers: ");
	scanf("%d %d", &p1, &p2);
	sa.sin_port = p1;
	sb.sin_port = p2;

	/*
	printf("Give server address and port number: ");
	scanf("%s %d", s, &a); 
	sa.sin_addr.s_addr = inet_addr(s);
	sa.sin_port = a;
	*/

	i = connect(sockfd, (struct sockaddr *) &sa, sizeof(sa));
	j = connect(sockfd2, (struct sockaddr *) &sb, sizeof(sb));
	
	printf("socketfd, i: %d %d\n", sockfd, i);
	printf("socketfd2, j: %d %d\n", sockfd2, j);

	int p, q, r;
	printf("Enter three numbers: ");
	scanf("%d %d %d", &p, &q, &r);
	
	if(p == p1) {
		send(sockfd, &q, 4, 0);
		send(sockfd2, &r, 4, 0);
	} else if (p == p2) {
		send(sockfd2, &q, 4, 0);
		send(sockfd, &r, 4, 0);
	}

}























