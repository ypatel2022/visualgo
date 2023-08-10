#include <algorithm>
#include <random>

#include "Constants.h"
#include "Visualizer.h"
#include "SortingAlgorithms.h"

Visualizer::Visualizer(Settings& settings, sf::RenderWindow& window)
	:m_Settings(settings)
{
	// set window position
	m_Position = sf::Vector2f(window.getSize().x / 5.0f + PADDING * 2.0f, PADDING);
	m_Size = sf::Vector2f(4.0f * window.getSize().x / 5.0f - PADDING * 3.0f, window.getSize().y - PADDING * 2.0f);

	// create elements
	for (int32_t i = 0; i < settings.GetNumberOfElements(); i++)
	{
		const float space = 2.0f;

		// makes max value of elements max height and min value of elements min height
		// creating a linear size distribution
		float multiplier = m_Size.y / settings.GetNumberOfElements();
		float height = i * multiplier;

		float width = std::max(m_Size.x / settings.GetNumberOfElements() - space, 1.0f);

		sf::Vector2f position(m_Position.x + i * (width + space), m_Position.y + m_Size.y - height);
		sf::Vector2f size(width, height);

		Element element(i, position, size);
		m_Elements.push_back(element);
	}
}

Visualizer::~Visualizer() {}

void Visualizer::Update()
{
	// SortingAlgorithms::Sort(array, size, m_Settings.GetCurrentAlgorithm());
}


void Visualizer::Render(sf::RenderWindow& window)
{
	// render elements
	for (Element element : m_Elements)
	{
		if (element.GetIsSwapped() == true) 
		{
			element.Render(window, sf::Color::Green);

		}
		else
		{
			element.Render(window, sf::Color::White);
		}
		
	}

	// render border
	sf::RectangleShape border(m_Size);
	border.setPosition(m_Position);
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineColor(sf::Color::White);
	border.setOutlineThickness(1.0f);
	window.draw(border);
}

void Visualizer::Randomize()
{
	auto rng = std::default_random_engine{};

	rng.seed(std::random_device()());

	std::shuffle(std::begin(m_Elements), std::end(m_Elements), rng);

	UpdateElements();
}

void Visualizer::UpdateElements()
{
	for (int32_t i = 0; i < m_Values.size(); i++)
	{

	}

	for (int32_t i = 0; i < m_Settings.GetNumberOfElements(); i++)
	{
		const float space = 2.0f;

		sf::Vector2f size = m_Elements[i].GetSize();

		float width = size.x;
		float height = size.y;

		sf::Vector2f position(m_Position.x + i * (width + space), m_Position.y + m_Size.y - height);

		m_Elements[i].SetPosition(position);
		m_Elements[i].SetSize(size);
	}
}


std::vector<int32_t>& Visualizer::GetValues()
{
	return m_Values;
}

std::vector<Element>& Visualizer::GetElements()
{
	return m_Elements;
}
