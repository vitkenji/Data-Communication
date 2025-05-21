#include "client.hpp"

int main()
{
	Client* client = Client::getInstance();
	if (client->connectToServer())
	{
		while (true) 
		{
			char message[1024];
			std::cout << "type message: ";
			std::cin.getline(message, sizeof(message));

			client->sendData(message);
		}
	}	
	return 0;
}
