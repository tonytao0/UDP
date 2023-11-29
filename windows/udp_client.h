#ifndef _UDP_CLIENT_H_
#define _UDP_CLIENT_H_

#include "WinScoketInit.h"

class UDPClient :public WinScoketInit
{
public:
	UDPClient(std::string ip = "127.0.0.1",uint16_t port = 8888);

	~UDPClient();

	void setIP(std::string ip);

	void setPort(uint16_t port);

	bool connect();

	void close();

	void send(const std::string& msg, struct sockaddr_in serverAddr);

	void send(const char*, size_t len, struct sockaddr_in serverAddr);

	uint32_t recv(char* buf, uint32_t len, struct sockaddr_in serverAddr);

	sockaddr_in  getServer();


private:
	std::string m_ip;
	uint16_t m_port;
	SOCKET m_sockfd;
	struct sockaddr_in m_sock_addr;
};

#endif // !_UDP_CLIENT_H_
