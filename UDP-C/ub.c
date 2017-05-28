#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
int sockfd, a, b, i, len;
struct sockaddr_in sa, ta, tb;
len = sizeof(ta);
sockfd = socket(AF_INET, SOCK_DGRAM, 0);
sa.sin_addr.s_addr = INADDR_ANY;
sa.sin_family = AF_INET;
sa.sin_port = 6001;

i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
printf("sockfd: %d and bind: %d\n", sockfd, i);

recvfrom(sockfd, &a, 4, 0, (struct sockaddr *)&ta, &len);
printf("Received %d from port %d\n", a, ta.sin_port);

recvfrom(sockfd, &b, 4, 0, (struct sockaddr *)&tb, &len);
printf("Received %d from port %d\n", b, tb.sin_port);

// a = a*2;
sendto(sockfd, &a, 4, 0, (struct sockaddr *)&tb, sizeof(tb));
sendto(sockfd, &b, 4, 0, (struct sockaddr *)&ta, sizeof(ta));
}
