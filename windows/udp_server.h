#ifndef _UDP_SERVER_H_
#define _UDP_SERVER_H_

#include "WinScoketInit.h"

class UDPServer:public WinScoketInit
{
public:
	UDPServer(std::string ip = "", uint16_t port = 8888);

	~UDPServer();

	void setIP(std::string ip);

	void setPort(uint16_t port);

	bool connect();

	bool reconnect(std::string ip, uint16_t port);

	void close();

	void send(const std::string& msg, sockaddr_in clientAddr);

	void send(const char*, size_t len,sockaddr_in clientAddr);

	uint32_t recv(char* buf, uint32_t len, sockaddr_in clientAddr);

	sockaddr_in getClient();

private:
	std::string m_ip;
	uint16_t m_port;
	SOCKET m_sockfd;
	struct sockaddr_in m_sock_addr;

	struct sockaddr_in clientAddr;
};

#endif // !_UDP_SERVER_H_