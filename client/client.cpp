#include "client.hpp"
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>

	Client* Client::instance = nullptr;

	Client* Client::getInstance()
	{
		if(instance == nullptr) { instance = new Client(); }
		return instance;
	}

	Client::~Client()
	{
		if (client_socket != -1)
		{
			close(client_socket);
		}
		delete instance;
		instance = nullptr;
	}

	Client::Client(const std::string &host, int port):host(host), port(port), client_socket(-1)
	{
	
	}

	bool Client::connectToServer()
	{
		client_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (client_socket == -1)
		{
			std::cerr << "error creating socket" << std::endl;
			return false;
		}
		sockaddr_in server_address;
		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(port);
		server_address.sin_addr.s_addr = inet_addr(host.c_str());

		if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
		{
			std::cerr << "connection failed" << std::endl;
			return false;
		}

		std::cout << "connected to server at " << host << ": " << port << std::endl; 
		return true;
	}

	void Client::sendData(const std::string &message)
	{
		if (send(client_socket, message.c_str(), message.length(), 0) == -1)
		{
			std::cerr << "failed to send data" << std::endl;
		}
		else
		{
			std::cout << "sent data: " << message << std::endl;
		}
	}

