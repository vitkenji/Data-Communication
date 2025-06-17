#pragma once
#include "input_manager.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <time.h>
#include <string>
#include <fstream>
#include "../coordinate.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

	class Observer
	{
	protected:
		InputManager* pInput;

	public:
		Observer();
		~Observer();

		virtual void notifyPressed(std::string key) = 0;
		virtual void notifyReleased(std::string key) = 0;

	};
