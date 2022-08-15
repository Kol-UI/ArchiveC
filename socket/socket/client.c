
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc , char *argv[])
{
    struct sockaddr_in cli_addr;

    int sock = socket(AF_INET , SOCK_STREAM , 0);

    cli_addr.sin_family = AF_INET;
    cli_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    cli_addr.sin_port = htons( 8888 );







    connect(sock , (struct sockaddr *)&cli_addr , sizeof(cli_addr));

    printf("Connected\n");

    char buff_cli[1024], buff_srv[2000];
    while(buff_cli[0] != '.')
    {
        printf("Enter message : ");
        scanf("%s" , buff_cli);

        send(sock , buff_cli , strlen(buff_cli) , 0);
    }

    close(sock);

    return 0;
}