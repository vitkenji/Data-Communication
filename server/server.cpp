#include "server.hpp"
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

Server* Server::instance = nullptr;

Server* Server::getInstance()
{
	if (instance == nullptr) {instance = new Server();}
	return instance;
}

Server::Server(const std::string &host, int port): decoder(Decoder::getInstance())
{
	this->host = host;
	this->port = port;
	this->server_socket = -1;
	this->client_socket = -1;
}

Server::~Server()
{
	if (server_socket != -1) { close(server_socket);}
	if (client_socket != -1) { close(client_socket);}
	delete instance;
	instance = nullptr;
}

bool Server::init()
{
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1)
	{
		std::cerr << "Error creating socket" << std::endl;
		return false;
	}
	
	sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	server_address.sin_addr.s_addr = inet_addr(host.c_str());

	if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
	{
		std::cerr << "error binding socket" << std::endl;
		return false;
	}

	if(listen(server_socket, 1) < 0)
	{
		std::cerr << "error listening socket" << std::endl;
		return false;
	}

	std::cout << "server listening on " << host << ": " << port << std::endl;
	return true;
}

void Server::acceptConnection()
{
	sockaddr_in client_address;
	socklen_t client_length = sizeof(client_address);
	client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_length);
	if (client_socket == -1)
	{
		std::cerr << "error accepting client connection"<< std::endl;
		return;
	}
	std::cout << "client connected"<< std::endl;

}

void Server::receiveData()
{
	char buffer[1024];
	while (true)
	{
		int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
		if (bytes_received == -1)
		{
			std::cerr << "error receiving data" << std::endl;
			return;
		}
		if (bytes_received > 0)
		{
			buffer[bytes_received] = '\0';
			std::string binary = decoder->b8zs_decoder(buffer);
			std::string encrypted = decoder->binary_to_encrypted(binary);
			std::string decrypted = decoder->encrypt_message(encrypted);

			std:: cout << "received: " << buffer << std::endl;
			std:: cout << "binary: " << binary << std::endl;
			std:: cout << "encrypted: " <<  encrypted << std::endl;  
			std:: cout << "decrypted: " << decrypted << std::endl;
		}
	}
}
