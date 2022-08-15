
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc , char *argv[])
{
    struct sockaddr_in serv_addr , cli_addr;

    int sock = socket(AF_INET , SOCK_STREAM , 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons( 8888 );

    bind(sock,(struct sockaddr *)&serv_addr , sizeof(serv_addr));

    listen(sock , 5);

    socklen_t clilen;
    clilen = sizeof(cli_addr);
    int newfd = accept(sock, (struct sockaddr *)&cli_addr, &clilen);

    char buff[2000];
    while(1)
    {
        if(recv(newfd , buff , sizeof(buff)-1, 0) > 0){
            puts(buff);
        }
    }

    close(newfd);
    close(sock);

    return 0;
}