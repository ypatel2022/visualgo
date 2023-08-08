#pragma once

#include <SFML/Graphics.hpp>

#include "Settings.h"

class Sidebar
{
private:
	sf::Vector2f m_Position = sf::Vector2f(50, 50);
	sf::Vector2f m_Size = sf::Vector2f(300, 1000);

	Settings m_Settings;

public:
	Sidebar(Settings& settings, sf::RenderWindow& window);

	~Sidebar();

	void Update();

	void Render(sf::RenderWindow& window);
};

