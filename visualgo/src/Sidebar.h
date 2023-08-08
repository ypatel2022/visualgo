#pragma once

#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "ui/Button.h"

class Sidebar
{
private:
	sf::Vector2f m_Position = sf::Vector2f(50, 50);
	sf::Vector2f m_Size = sf::Vector2f(300, 1000);

	Settings m_Settings;

	std::vector<Button*> m_Buttons;

public:
	Sidebar(Settings& settings, sf::RenderWindow& window);

	~Sidebar();

	void Update(sf::RenderWindow& window);

	void Render(sf::RenderWindow& window);
};

