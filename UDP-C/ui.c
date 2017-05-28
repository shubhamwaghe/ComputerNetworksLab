#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
int sockfd, length, m, n, k;
struct sockaddr_in sa, da, ta;
length = sizeof(sa);
sockfd = socket(AF_INET, SOCK_DGRAM,0);
ta.sin_family = AF_INET;
da.sin_addr.s_addr = inet_addr("127.0.0.1");
da.sin_family = AF_INET;
da.sin_port = 6001;
printf("Give a number to send: ");
scanf("%d", &m);
sendto(sockfd, &m, 4, 0, (struct sockaddr *)&da, length);

printf("Give another number to send: ");
scanf("%d", &n);
sendto(sockfd, &n, 4, 0, (struct sockaddr *)&da, length);

int prod;
recvfrom(sockfd, &prod, 4, 0, (struct sockaddr *)&ta, &length);

printf("Received: Product = %d\n", prod);
}
