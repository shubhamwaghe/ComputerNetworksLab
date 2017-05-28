#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
int sockfd, a, b, c, i, len;
struct sockaddr_in sa, ta, tb, tc;
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

recvfrom(sockfd, &c, 4, 0, (struct sockaddr *)&tc, &len);
printf("Received %d from port %d\n", c, tc.sin_port);


int arr[3] = { a, b, c };
int arrsa[3] = { b, c, b+c };
int arrsb[3] = { c, a, c+a };
int arrsc[3] = { a, b, a+b };

// printf("Received %d %d %d\n", arr[0], arr[1], arr[2]);
sendto(sockfd, &arrsa, 12, 0, (struct sockaddr *)&ta, sizeof(ta));
sendto(sockfd, &arrsb, 12, 0, (struct sockaddr *)&tb, sizeof(tb));
sendto(sockfd, &arrsc, 12, 0, (struct sockaddr *)&tc, sizeof(tc));
}


















