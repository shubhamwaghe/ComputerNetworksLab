#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
main() {
int sockfd, p, q, r, s, i, len;
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

recvfrom(sockfd, &p, 4, 0, (struct sockaddr *)&ta, &len);
printf("Received %d from port %d\n", p, ta.sin_port);

recvfrom(sockfd, &q, 4, 0, (struct sockaddr *)&tb, &len);
printf("Received %d from port %d\n", q, tb.sin_port);

// Second Window
recvfrom(sockfd, &r, 4, 0, (struct sockaddr *)&tc, &len);
printf("Received %d from port %d\n", r, tc.sin_port);

recvfrom(sockfd, &s, 4, 0, (struct sockaddr *)&td, &len);
printf("Received %d from port %d\n", s, td.sin_port);

int prod1, prod2;
if (ta.sin_port == tb.sin_port) {
prod1 = p*q;
prod2 = r*s;
} else if(ta.sin_port == tc.sin_port){
prod1 = p*r;
prod2 = q*s;
} else if(ta.sin_port == td.sin_port) {
prod1 = p*s;
prod2 = q*r;
}


printf("Received %d %d %d %d\n", p, q, r, s);
printf("Sum of numbers: %d\n", p+q+r+s);

sendto(sockfd, &prod1, 4, 0, (struct sockaddr *)&ta, sizeof(ta));
sendto(sockfd, &prod2, 4, 0, (struct sockaddr *)&tb, sizeof(tb));

}


















