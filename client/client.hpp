#pragma once
#include <iostream>
#include "coder.hpp"

class Client
{
private:
	static Client* instance;
	Client(const std::string &host="127.0.0.1", int port=8080);
	int client_socket;
	std::string host;
	int port;
	Coder* coder;

public:
	~Client();
	static Client* getInstance();
	bool connectToServer();
	void sendData(const std::string &message);

};
