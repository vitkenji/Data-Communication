#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../coordinate.hpp"
#include <string.h>

	class GraphicManager
	{
	private:
		sf::RenderWindow* window;
		sf::View view;
		std::map<const char*, sf::Texture*> textureMap;
		std::map<const char*, sf::Font*> fontMap;
		static GraphicManager* instance;

		GraphicManager();

	public:
		~GraphicManager();

		static GraphicManager* getInstance();
		void render(sf::RectangleShape* body);
		void render(sf::Text* text);
		void display();
		void clear();
		bool isWindowOpen();
		void closeWindow();
		void setWindowSize(Math::CoordinateU size);
		Math::CoordinateU getWindowSize() const;
		Math::CoordinateF getHudPosition() const;
		sf::Texture* loadTexture(const char* path);
		sf::Font* loadFont(const char* path);
		void centerView(Math::CoordinateF position);
		sf::RenderWindow* getWindow() const;

	};
