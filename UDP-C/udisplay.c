#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
int sockfd, a1, a2, a3, s, i, len;
struct sockaddr_in sa, ta, tb, tc, td;
len = sizeof(ta);
sockfd = socket(AF_INET, SOCK_DGRAM, 0);
sa.sin_addr.s_addr = INADDR_ANY;
sa.sin_family = AF_INET;
sa.sin_port = 6001;
ta.sin_family = AF_INET;
tb.sin_family = AF_INET;

i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
printf("sockfd: %d and bind: %d\n", sockfd, i);

recvfrom(sockfd, &a1, 4, 0, (struct sockaddr *)&ta, &len);
printf("Received %d from port %d\n", a1, ta.sin_port);

}


















