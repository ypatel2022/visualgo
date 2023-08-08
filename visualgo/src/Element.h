#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

class Element
{
private:
	int32_t m_Value;
	sf::Vector2f m_Position;
	sf::Vector2f m_Size;
	sf::RectangleShape m_Shape;


public:

	Element(int32_t value, sf::Vector2f position, sf::Vector2f size);

	~Element();

	void SetValue(int32_t value);

	void SetPosition(sf::Vector2f position);

	void Render(sf::RenderWindow& window, sf::Color color);

	void SetSize(sf::Vector2f size);

	int32_t GetValue();

	sf::Vector2f GetPosition();

	sf::Vector2f GetSize();
};

