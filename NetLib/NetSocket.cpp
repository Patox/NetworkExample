#include "NetSocket.h"

NetSocket::NetSocket(const in_addr_t &addr, const short &port, const int &domain, const int &type, const int &protocol) {
	this->addr = addr;
	this->port = port;
	this->domain = domain;
	this->type = type;
	this->protocol = protocol;

	char server_message[256] = "You have reached the server!";

	// create a server socket
	int server_socket;
	server_socket = socket(domain, type, protocol);

	// define the server address
	struct sockaddr_in address;
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr = addr;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &address, sizeof(address));

	// listen for client connections
	listen(server_socket, 5);
	
	// accept the client connetions
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	// send the message to the client
	send(client_socket, server_message, sizeof(server_message), 0);
	
	// close the socket
	// second argument specifies the action to perfrom
	// 0 : Stop receiving data for this socket. If further data arrives, reject it
	// 1 : Stop trying to transmit data from this socket. Discard any data waiting to be sent.
    //	   Stop looking for acknowlegdement of data already sent, don´t retransmit it if it is lost.
	// 2 : Stop both reception and transmission
	shutdown(server_socket, 0);
	
}

