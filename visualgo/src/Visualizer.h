#pragma once

#include <iostream>
#include <vector>

#include "Element.h"
#include "Settings.h"

class Visualizer
{
private:
	std::vector<Element> m_Elements;
	std::vector<int32_t> m_Values;
	

	sf::Vector2f m_Position = sf::Vector2f(400, 50);
	sf::Vector2f m_Size = sf::Vector2f(1400, 1000);

	Settings m_Settings;


public:
	Visualizer(Settings& settings);

	~Visualizer();

	void Update();

	void Render(sf::RenderWindow& window);

	void Randomize();

	void UpdateElements();

	std::vector<Element> GetElements();

};


