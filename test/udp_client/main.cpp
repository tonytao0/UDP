#include <iostream>
#include <thread>
#include "../../src/Client.h"

int main()
{
    UDPClient client;

	client.setIP("127.0.0.1");
	client.setPort(9999);

	if (client.connect())
	{
		char buf[1024] = { 0 };
		while (true)
		{
			client.send("this is udp clinet",client.getServer());

			int ret = client.recv(buf, 1024, client.getServer());
			if (ret > 0)
			{
				std::cout << std::string(buf, ret) << std::endl;
			} 

			//std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
	}
}