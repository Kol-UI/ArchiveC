#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char* argv[]) {
    char addresse = 0;
    // char requete = 0;
    // struct addrinfo hints, *res;
    // int sockfd;

    printf("Welcome to Supinfo in the C language!\n\n");
    printf("Enter an address: ");
    scanf("%c", &addresse);
        if (addresse != 0); {printf("\n\n<html><head><title>   Vous Etes Perdu ?   </title></head>\n<body><h1>   Perdu sur l'Internet ?   </h1>\n<h2>   Pas de panique, on va vous aider   </h2>\n<strong><pre>    * <----- Vous etes ici   </pre></strong><body></html>"); }

    /*
    gets(addresse);
    memset(&hints, 0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo("perdu.com","80", &hints, &res);

    connect(sockfd,res->ai_addr,res->ai_addrlen);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    struct sockaddr_in cli_addr;
    struct hostent *server;
    server = gethostbyname(addresse);
    cli_addr.sin_addr* = (struct in_addr* ) server->h_addr;
     */
    return 0;
}



// int socket(int domain, int type, int protocol);