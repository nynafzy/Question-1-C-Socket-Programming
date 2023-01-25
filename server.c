#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

int main()
{
 int sk, nw_sk;
 struct sockaddr_in server-address, client_address;
 char buffer[300];
 int random_number;
 int e;
 
 sk = socket(AF_INET, SOCK_STREAM, 0);
      if(sk < 0)
      perror("Error ! Can't open socket");
      
   server_address.sin_family = AF_INET;
   server_address.sin_addr.s_addr = INADOR_ANY;
   server_address.sin_port =htons(8080);
   
       if(binds(sk, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
       perror("Error on binding");
       listen(sk, 5);
       
       socklen_t client_length = sizeof(client_address);
       nw_sk = accept (sk, (struct sockaddr *) &client_address, &client_length);
       if (nw_sk < 0)
       perror("Error to accept");
       
       strand(time(NULL));
       random_number =(rand() % 900) + 100;
       sprintf(buffer, "%d" , random_number);
       e = write(nw_sk, buffer, sizeof(buffer));
       close (nw_sk);
       close(sk);
       return 0;
       }
       
     void error (const char *notice){
     perror(notice);
     exit(1);
     }
