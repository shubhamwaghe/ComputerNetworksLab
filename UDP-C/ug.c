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

recvfrom(sockfd, &a2, 4, 0, (struct sockaddr *)&tb, &len);
printf("Received %d from port %d\n", a2, tb.sin_port);

// Second Window
recvfrom(sockfd, &a3, 4, 0, (struct sockaddr *)&tc, &len);
printf("Received %d from port %d\n", a3, tc.sin_port);

int p, q, r;
if (ta.sin_port == tb.sin_port) {
p = a1;
q = a2;
r = a3;
} else if(ta.sin_port == tc.sin_port){
p = a1;
q = a3;
r = a2;
} else if(tb.sin_port == tc.sin_port) {
p = a2;
q = a3;
r = a1;
}


// printf("Received %d %d %d %d\n", p, q, r, s);

printf("Q7) Required: (p+q)*r: %d\n", (p+q)*r);
printf("Q8) Required: q*r+p: %d\n", q*r+p);

//sendto(sockfd, &prod1, 4, 0, (struct sockaddr *)&ta, sizeof(ta));
//sendto(sockfd, &prod2, 4, 0, (struct sockaddr *)&tb, sizeof(tb));

}


















