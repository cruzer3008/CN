#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> 
#include <arpa/inet.h>

#define bufsize 1024

int main(){

  int clientSocket;
  char buffer[1024],fname[255];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;

  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  printf("\nEnter filename: ");scanf("%s",fname);

  send(clientSocket,fname,255,0);
  printf("\nResponse:\n");
  while((recv(clientSocket, buffer, bufsize, 0))>0)
    printf("%s",buffer);
  printf("\n");
   

  return close(clientSocket);
}
