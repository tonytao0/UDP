#include "../../src/Server.h"
#pragma warning(disable:4996)

int main()
{
	UDPServer server;

	server.setIP("127.0.0.1");
	server.setPort(9999);

	if (server.connect())
	{
		char buf[1024] = { 0 };
		std::cout << "connect success\n";

		while (true)
		{
			int ret = server.recv(buf, 1024,server.getClient());
			if (ret > 0)
			{
				buf[ret] = '\0';
				printf("recive data from %s: \r\n", inet_ntoa(server.getClient().sin_addr));
				printf(buf);
			}

			server.send("this is udp server", strlen("this is udp server"), server.getClient());
		}
	}
}