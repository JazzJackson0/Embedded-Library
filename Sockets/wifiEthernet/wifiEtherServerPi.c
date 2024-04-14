/*Modified version of code from 
https://www.codeproject.com/Articles/586000/Networking-and-Socket-Programming-Tutorial-in-C */
//Server: Raspberry Pi
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main(void) {
	
	int server_socket = 0, connfd = 0;
	struct sockaddr_in serv_addr;
	char sendBuff[1025];
	int numrv;
	
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	printf("socket retrieve success\n");
	
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);//Change to address outside of local machine
	serv_addr.sin_port = htons(5000);
	
	bind(server_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	
	if(listen(listenfd, 10) == -1) {
		
		printf("Failed to listen\n");
		return -1;
	}
	
	while(1) {
		
		connfd = accept(server_socket, (struct sockaddr*)NULL, NULL);
		
		strcpy(sendBuff, "Message from server");
		write(connfd, sendBuff, strlen(sendBuff));
		
		close(connfd);
		sleep(1);
	}
	
	return 0;
}



/*			TO-DO
 * 			-----
 *  - Change Address in struct to one outside of the local machine
 *
 *  - 
 *
 *  - 
 *  */
 
//End--------------
