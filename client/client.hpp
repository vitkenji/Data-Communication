#pragma once
#include <iostream>

class Client
{
private:
	static* Client instance;
	Client();
public:
	~Client();
	static* Client* getInstance();
}
