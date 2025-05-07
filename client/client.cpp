#include "client.hpp"

	Client* Client::instance = nullptr;

	Client* Client::getInstance()
	{
		if(instance == nullptr) { instance = new Client(); }
		return instance;
	}

	Client::~Client()
	{
		delete instance;
		instance = nullptr;
	}
