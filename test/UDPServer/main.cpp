#include "../../src/Server.h"

int main()
{
	UDPServer server;

	//server.resetIP("127.0.0.1");
	server.resetPort(9999);

	if (server.connect())
	{
		char buf[1024] = { 0 };
		std::cout << "connect success\n";
		server.run();
	}
}