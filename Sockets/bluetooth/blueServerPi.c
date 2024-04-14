/*Modified version of  code obtained from 
https://people.csail.mit.edu/albert/bluez-intro/x45.html */
//Server/Host: Raspberry Pi
//Sets up the server to listen for connection requests
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
//To Compile: gcc filename -lbluetooth

//Macros & Prototypes--------------------------------------------------------------
int bluetoothScan(void);

//Global Variables-----------------------------------------------------------------

int main(void) {
	
	//bluetoothScan();
	struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };
	char buf[1024] = { 0 };
	int s, client, bytes_read;
	socklen_t opt = sizeof(rem_addr);
	
	s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	
	// bind socket to port 1 of the first available
	// local bluetooth adapter
	loc_addr.rc_family = AF_BLUETOOTH;
	loc_addr.rc_bdaddr = *BDADDR_ANY;
	loc_addr.rc_channel = (uint8_t) 1;
	bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));
	
	listen(s, 1);
	
	client = accept(s, (struct sockaddr *)&rem_addr, &opt);
	
	ba2str( &rem_addr.rc_bdaddr, buf );
	fprintf(stderr, "accepted connection from %s\n", buf);
	memset(buf, 0, sizeof(buf));
	
	bytes_read = read(client, buf, sizeof(buf));
	if( bytes_read > 0 ) {
		
		printf("received [%s]\n", buf);
	}
	
	close(client);
	close(s);
	return 0;
}

int bluetoothScan() {
	
	inquiry_info *ii = NULL;
	int max_rsp, num_rsp;
	int dev_id, sock, len, flags;
	int i;
	char addr[19] = { 0 };
	char name[248] = { 0 };
	dev_id = hci_get_route(NULL);
	sock = hci_open_dev( dev_id ); 
	
	if (dev_id < 0 || sock < 0) {
		
		perror("opening socket");
		exit(1);
	}
	
	len = 8;
	max_rsp = 255;
	flags = IREQ_CACHE_FLUSH;
	ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
	
	num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
	
	if( num_rsp < 0 ) perror("hci_inquiry");
	
	for (i = 0; i < num_rsp; i++) {
		
		ba2str(&(ii+i)->bdaddr, addr);
		memset(name, 0, sizeof(name));
		if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name),
			name, 0) < 0)
		strcpy(name, "[unknown]"); 
		printf("%s %s\n", addr, name);
	}
	
	free( ii );
	close( sock );
	return 0;
}


/*			TO-DO
 * 			-----
 *  - 
 *
 *  - 
 *
 *  - 
 *  */
 
//End--------------
