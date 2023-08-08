#include "Sidebar.h"

#include "Constants.h"

Sidebar::Sidebar(Settings& settings, sf::RenderWindow& window)
	: m_Settings(settings)
{
	// end the sidebar at 1/5 of the window width
	m_Position = sf::Vector2f(PADDING, PADDING);
	m_Size = sf::Vector2f(window.getSize().x / 5.0f, window.getSize().y - PADDING * 2.0f);

	// create the buttons
	sf::Vector2f buttonSize = sf::Vector2f(m_Size.x - PADDING * 2.0f, 50);
	sf::Vector2f buttonPosition = sf::Vector2f(m_Position.x + PADDING, m_Position.y + PADDING);

	m_Buttons.push_back(new Button(buttonPosition, buttonSize, "Randomize", [&]() {
		std::cout << "started" << std::endl;
		}));


}

Sidebar::~Sidebar()
{
	for (Button* button : m_Buttons)
	{
		delete button;
	}
}

void Sidebar::Update(sf::RenderWindow& window)
{
	// update buttons
	for (Button* button : m_Buttons)
	{
		button->Update(window);
	}
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

	// render buttons
	// std::vector<Button*> m_Buttons;
	for (Button* button : m_Buttons)
	{
		button->Render(window);
	}
}
