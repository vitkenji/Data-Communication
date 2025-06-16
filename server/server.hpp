#pragma once
#include <iostream>
#include <string>
#include "decoder.hpp"

class Server
{
private:
	static Server* instance;
	Server(const std::string &host = "127.0.0.1", int port=8080);

	Decoder* decoder;

	int server_socket;
	int client_socket;
	std::string host;
	int port;

public:
	~Server();
	static Server* getInstance();
	bool init();
	void acceptConnection();
	void receiveData();
};
