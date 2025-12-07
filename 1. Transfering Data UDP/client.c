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
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;
    char *data = NULL;


    reader("file.txt", &data);

    printf("%s\n\n\n", data);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    
    // create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    int counter=0;
    int fileSize = strlen(data);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        exit(0);
    }

    while(counter < fileSize){
        

        if( (fileSize - counter) <= 100){
            strncpy(buffer, data+  counter , fileSize - counter);
            
            buffer[(fileSize - counter)] = '\0';
            counter+=(fileSize - counter);
            
        }else{
            strncpy(buffer, data +counter, MAXLINE);
            buffer[100] = '\0';

            counter+=MAXLINE;
        }

        sendto(sockfd, buffer , strlen(buffer), 0, (struct sockaddr*)NULL, sizeof(servaddr));

    }

    close(sockfd);
    free(data);
    return 0;
}