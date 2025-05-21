#include "server.hpp"

int main()
{
	Server* server = Server::getInstance();
	if (server->init())
	{
		while (true)
		{
			server->acceptConnection();
			server->receiveData();
		}
	}
	return 0;
}
