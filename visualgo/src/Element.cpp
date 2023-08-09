#include "Element.h"


Element::Element() : m_Value(0), m_Position(sf::Vector2f(0, 0)), m_Size(sf::Vector2f(0, 0)) {
	m_Shape.setSize(m_Size);
	m_Shape.setPosition(m_Position);
}

Element::Element(int32_t value, sf::Vector2f position, sf::Vector2f size)
	:m_Value(value), m_Position(position), m_Size(size)
{
	m_Shape.setFillColor(sf::Color::White);
	m_Shape.setPosition(position);
	m_Shape.setSize(size);
}

Element::~Element() { }

void Element::Render(sf::RenderWindow& window, sf::Color color = sf::Color::White)
{
	if (color.r != 255 && color.b != 255 && color.g != 255)
	{
		m_Shape.setFillColor(color);
	}

	window.draw(m_Shape);
}

void Element::SetPosition(sf::Vector2f position)
{
	m_Position = position;
	m_Shape.setPosition(position);
}

void Element::SetSize(sf::Vector2f size)
{
	m_Size = size;
	m_Shape.setSize(size);
}

void Element::SetValue(int32_t value)
{
	m_Value = value;

}

int32_t Element::GetValue()
{
	return m_Value;
}

sf::Vector2f Element::GetPosition()
{
	return m_Position;
}

sf::Vector2f Element::GetSize()
{
	return m_Size;
}