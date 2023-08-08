#pragma once

#include <functional>

#include "SFML/Graphics.hpp"

class Button
{
private:
	sf::Vector2f m_Position;
	sf::Vector2f m_Size;

	sf::RectangleShape m_Shape;

	sf::Text m_Text;

	sf::Font m_Font;

	std::function<void()> clickCallback;

	bool m_IsPressed = false;

public:
	Button(sf::Vector2f position, sf::Vector2f size, std::string text, std::function<void()> onClick);

	~Button();

	void Update(sf::RenderWindow& window);

	void Render(sf::RenderWindow& window);

	bool IsClicked(sf::RenderWindow& window);

};

