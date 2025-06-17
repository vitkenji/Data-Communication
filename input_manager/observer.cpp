#include "observer.hpp"

	Observer::Observer()
	{
		this->pInput = InputManager::getInstance();
		pInput->attach(this);
	}

	Observer::~Observer()
	{
		pInput->detach(this);
	}
