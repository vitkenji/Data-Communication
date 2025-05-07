#pragma once
#include <iostream>

class Server
{
private:
	static Server* instance;
	Server();
public:
	~Server();
	static Server* getInstance();
}
