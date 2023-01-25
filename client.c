#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() 
{
int sk;
struct sockaddr_in server_address;
char buffer[300];
int e;

sk = socket(AF_INET, SOCK_STREAM, 0);
    if (sk < 0)
    perror ("Error ! Can't open socket");
    
    server_address.sin_family = AF_INET;
    server_adress.sin_addr.s_addr = inet_addr("192.168.31.128");
    server_address.sin_port = htons(8080);
    
    if(connect (sk, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
    perror ("Can't Connect");
    
    bfz(buffer, sizeof(buffer));
    e = read(sk,buffer, sizeof (buffer)-1);
    if (e < 0)
    perror("Error reading from socket");
    printf ("This is the random number: %s\n", buffer);
    close(sk)
    return 0;
    }
    
    void error(const char *notice){
    perror(notice);
    exit(1)
    }
    
