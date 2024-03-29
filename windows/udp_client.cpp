#include "udp_client.h"
#pragma warning(disable : 4996)


UDPClient::UDPClient(std::string ip, uint16_t port)
	: m_ip(ip)
	, m_port(port)
	, m_sockfd(INVALID_SOCKET)
	, m_sock_addr{0}
{
	//default ip="127.0.0..1", port=8888.
	memset(&m_sock_addr, 0, sizeof(sockaddr_in));
	m_sock_addr.sin_family = AF_INET;
	m_sock_addr.sin_port = htons(m_port);
	m_sock_addr.sin_addr.S_un.S_addr = inet_addr(m_ip.c_str());
}

UDPClient::~UDPClient()
{
}

void UDPClient::setIP(std::string ip)
{
	m_ip = ip;
}

void UDPClient::setPort(uint16_t port)
{
	m_port = port;
}

bool UDPClient::connect()
{
	//create socket.
	m_sockfd =  socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (m_sockfd == INVALID_SOCKET)
	{
		std::cout << "connect failed.\n";

		return false;
	}

	//config ip and port.
	memset(&m_sock_addr, 0, sizeof(m_sock_addr));
	m_sock_addr.sin_family = AF_INET;
	m_sock_addr.sin_port = htons(m_port);
	m_sock_addr.sin_addr.S_un.S_addr = inet_addr(m_ip.c_str());

	return true;
}

void UDPClient::close()
{
	if (INVALID_SOCKET != m_sockfd)
	{
		closesocket(m_sockfd);
	}
}

void UDPClient::send(const std::string &msg, struct sockaddr_in serverAddr)
{
	sendto(m_sockfd, msg.c_str(), msg.length(), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

void UDPClient::send(const char* msg, size_t len, struct sockaddr_in serverAddr)
{
	sendto(m_sockfd, msg, len, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

uint32_t UDPClient::recv(char* buf, uint32_t len, struct sockaddr_in serverAddr)
{
	int addr_len = sizeof(serverAddr);

	return recvfrom(m_sockfd, buf, len, 0, (sockaddr*)&serverAddr, &addr_len);
}

sockaddr_in  UDPClient::getServer()
{
	return m_sock_addr;
}
