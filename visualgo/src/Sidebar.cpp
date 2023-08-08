#include "Sidebar.h"

Sidebar::Sidebar(Settings& settings, sf::RenderWindow& window)
	: m_Settings(settings)
{

	// end the sidebar at 1/5 of the window width
	m_Position = sf::Vector2f(50.0f, 50.0f);
	m_Size = sf::Vector2f(window.getSize().x / 5.0f, window.getSize().y - 100.0f);
}

Sidebar::~Sidebar() {}

void Sidebar::Update()
{
}

void Sidebar::Render(sf::RenderWindow& window)
{
	// render border
	sf::RectangleShape border(m_Size);
	border.setPosition(m_Position);
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineColor(sf::Color::White);
	border.setOutlineThickness(1.0f);
	window.draw(border);
}
