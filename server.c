#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>



int main() {
int sockfd =  socket(AF_INET, SOCK_STREAM, 0);

//access the struct via addr variable
struct sockaddr_in addr;

//set socket to IPv4 Family
addr.sin_family = AF_INET;

//set socket port to 8080
addr.sin_port = htons(8080);

//converts string ip address into binary and stores it in the pointer address of sin_address
inet_aton("127.0.0.1", &addr.sin_addr);

// set socket option at socket level to reuse port and ip
int reuseaddr = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr));

//bind socket to ip address, this function takes the socket you want to bind to,and  changes addr type to struct sockaddr  for compilation.
bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

//listen for incoming connections, up to 10 pending.
listen(sockfd, 10);


struct socketaddr_in client_addr;
socklen_t client_len = sizeof(client_addr)

//accept connection from client
int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

//close the socket afterwards
close(client_sockfd)
close(sockfd)
}
