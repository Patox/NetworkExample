#ifndef _NETSOCKET_H_
#define _NETSOCKET_H_

#include "../GameLib/stdfx.h"
#include "../NetLib/stdfx.h"

// This object represents a network server or client socket.
class NetSocket {
private:
	// The host of the socket instance
	in_addr_t addr;
	// The port of the socket instance
	short port;
	// communication domain e.g., AF_INET (IPv4 protocol), AF_INET6 (IPv6 protocol)
	int domain;
	// communication type SOCK_STREAM: TCP(reliable, connection oriented), SOCK_DGRAM UDP(unreliable, connectionless)
	int type;
	// Protocol value for Internet Protocol(IP), wich is 0. This is the same number wich appears on protocol field in the
	// ip header of a a packet (man protocols for more details)
	int protocol;

public:
	NetSocket(const in_addr_t &addr, const short &port, const int &domain, const int &type, const int &protocol);

	const in_addr_t getAddr() {
		return this->addr;
	}

	const short &getPort() {
		return this->port;
	}

	const int &getDomain() {
		return this->domain;
	}

	const int &getType() {
		return this->type;
	}

	const int &getProtocol() {
		return this->protocol;
	}
};

#endif