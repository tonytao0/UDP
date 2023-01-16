#include <iostream>
#include <thread>
#include "../../src/Client.h"

int main()
{
    UDPClient client;

	client.resetIP("127.0.0.1");
	client.resetPort(9999);

	if (client.connect())
	{
		char buf[1024] = { 0 };
		while (true)
		{
			client.send("this is udp clinet");

			int ret = client.recv(buf, 1024);
			if (ret > 0)
			{
				std::cout << std::string(buf, ret) << std::endl;
			} 

			//std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
	}
}