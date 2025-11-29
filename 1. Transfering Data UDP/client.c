// udp client driver program
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>

#include "file_utils.h"

#define PORT 5000
#define MAXLINE 100

// Driver code
int main()
{   
    int sockfd, n;
    struct sockaddr_in servaddr;
    
    char *buffer = reader("file.txt");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    
    // create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    // connect to server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        exit(0);
    }

    sendto(sockfd, buffer , strlen(buffer), 0, (struct sockaddr*)NULL, sizeof(servaddr));
    

    close(sockfd);
}