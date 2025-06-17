#include "graphic_manager.hpp"

	GraphicManager* GraphicManager::instance = nullptr;

	GraphicManager* GraphicManager::getInstance()
	{
		if (instance == nullptr) { instance = new GraphicManager(); }
		return instance;

	}

	GraphicManager::GraphicManager() :
		window(new sf::RenderWindow(sf::VideoMode().getDesktopMode(), "Hero", sf::Style::Titlebar | sf::Style::Close)),
		view(sf::Vector2f(800 / 2, 600 / 2), sf::Vector2f(800, 600)), textureMap(), fontMap() {}

	GraphicManager::~GraphicManager()
	{
		std::map<const char*, sf::Texture*>::iterator i;
		for (i = textureMap.begin(); i != textureMap.end(); i++)
		{
			delete(i->second);
		}
		delete(window);
	}

	void GraphicManager::render(sf::RectangleShape* body)
	{
		window->draw(*body);
	}

	void GraphicManager::render(sf::Text* text)
	{
		window->draw(*text);
	}

	void GraphicManager::display()
	{
		window->display();
	}

	void GraphicManager::clear()
	{
		window->clear();
	}

	bool GraphicManager::isWindowOpen()
	{
		return window->isOpen();
	}

	void GraphicManager::closeWindow()
	{
		window->close();
	}

	void GraphicManager::setWindowSize(Math::CoordinateU size)
	{
		window->setSize(sf::Vector2u(size.x, size.y));
		view.setSize(size.x, size.y);
		window->setView(view);
	}

	Math::CoordinateU GraphicManager::getWindowSize() const
	{
		return Math::CoordinateU(window->getSize().x, window->getSize().y);
	}

	Math::CoordinateF GraphicManager::getHudPosition() const
	{
		return Math::CoordinateF(window->getView().getCenter().x - 580 , window->getView().getCenter().y - 380);
	}

	void GraphicManager::centerView(Math::CoordinateF position)
	{
		view.setCenter(position.x, position.y);
		window->setView(view);
	}

	sf::Texture* GraphicManager::loadTexture(const char* path)
	{
		std::map<const char*, sf::Texture*>::iterator i;
		for (i = textureMap.begin(); i != textureMap.end(); i++)
		{
			if (!strcmp(i->first, path)) { return i->second; }
		}

		sf::Texture* texture = new sf::Texture();
		if (!texture->loadFromFile(path)) { std::cout << "error loading texture file" << std::endl; exit(1); }
		textureMap.insert(std::pair<const char*, sf::Texture*>(path, texture));
		return texture;

	}

	sf::Font* GraphicManager::loadFont(const char* path)
	{
		std::map<const char*, sf::Font*>::iterator i;
		for (i = fontMap.begin(); i != fontMap.end(); i++)
		{
			if (!strcmp(i->first, path)) { return i->second; }
		}

		sf::Font* font = new sf::Font();
		if (!font->loadFromFile(path)) { std::cout << "error loading font file" << std::endl; exit(1); }
		fontMap.insert(std::pair<const char*, sf::Font*>(path, font));
		return font;
	}

	sf::RenderWindow* GraphicManager::getWindow() const
	{
		return window;
	}
