#pragma once
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

	class Observer;

	class InputManager
	{
	private:
		std::list<Observer*> observing;
		std::list<Observer*>::iterator i;
		std::map<sf::Keyboard::Key, std::string> keyMap;
		static InputManager* instance;

		InputManager();

	public:
		~InputManager();

		static InputManager* getInstance();
		void attach(Observer* pObserver);
		void detach(Observer* pObserver);
		void handleKeyPressed(sf::Keyboard::Key key);
		void handleKeyReleased(sf::Keyboard::Key key);
		std::string getKeyAsString(sf::Keyboard::Key key);

	};
