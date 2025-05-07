#include "server.hpp"

Server* Server::instance = nullptr;

Server* Server::getInstance()
{
	if (instance == nullptr) {instance = new Server();}
	return instance;
}

Server::~Server()
{
	delete instance;
	instance = nullptr;
}
