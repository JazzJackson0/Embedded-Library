/*Modified version of  code obtained from 
https://people.csail.mit.edu/albert/bluez-intro/x45.html */
//Client: BBB
/*Finds & lists all bluetooth devices in area
Then sends data out to a specified bluetooth address*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>
//To Compile: gcc filename -lbluetooth

//Macros & Prototypes--------------------------------------------------------------
int bluetoothScan(void);
int rfcommConnect(void);

//Global Variables-----------------------------------------------------------------

int main(void) {
	
	bluetoothScan();
	rfcommConnect();
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

int rfcommConnect(void) {
	
	struct sockaddr_rc addr = { 0 };
	int s, status;
	char dest[18] = "01:23:45:67:89:AB";
	
	// allocate a socket
	s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	
	// set the connection parameters (who to connect to)
	addr.rc_family = AF_BLUETOOTH; 
	addr.rc_channel = (uint8_t) 1; 
	str2ba( dest, &addr.rc_bdaddr );
	
	// connect to server
	status = connect(s, (struct sockaddr *)&addr, sizeof(addr));
	
	// send a message
	if( status == 0 ) {
		
		status = write(s, "hello!", 6);
	}
	
	if( status < 0 ) perror("uh oh");
	
	close(s);
	return 0;
}




/*			TO-DO
 * 			-----
 *  - Set destination bluetooth address to send data to.
 *
 *  - 
 *
 *  - 
 *  */
 
//End--------------
