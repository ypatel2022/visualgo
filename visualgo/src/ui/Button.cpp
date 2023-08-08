#include <iostream>

#include "Button.h"
#include <SFML/Graphics.hpp>

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text, std::function<void()> onClick)
	: m_Position(position), m_Size(size), clickCallback(onClick)
{
	if (!m_Font.loadFromFile("./res/fonts/GeneralSans.ttf"))
	{
		std::cout << "error loading font" << std::endl;
	}

	m_Shape = sf::RectangleShape(m_Size);
	m_Shape.setPosition(m_Position);
	m_Shape.setFillColor(sf::Color::White);

	//set up text
	m_Text.setString(text);
	m_Text.setFont(m_Font);
	m_Text.setCharacterSize(24);
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setPosition(m_Position.x + m_Size.x / 2.0f - m_Text.getGlobalBounds().width / 2.0f, m_Position.y + m_Size.y / 2.0f - m_Text.getGlobalBounds().height);
}

Button::~Button() {}

void Button::Update(sf::RenderWindow& window)
{
	if (IsClicked(window))
	{
		return;
	}
}

void Button::Render(sf::RenderWindow& window)
{
	window.draw(m_Shape);
	window.draw(m_Text);
}

bool Button::IsClicked(sf::RenderWindow& window)
{
	// use variable bool m_IsPressed to prevent multiple clicks while holding down mouse button


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_IsPressed)
		{
			return false;
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (mousePos.x > m_Position.x && mousePos.x < m_Position.x + m_Size.x &&
			mousePos.y > m_Position.y && mousePos.y < m_Position.y + m_Size.y)
		{

			m_IsPressed = true;

			clickCallback();
			return true;
		}

	}
	else
	{
		m_IsPressed = false;
	}

	return false;
}
