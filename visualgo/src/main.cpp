#include <SFML/Graphics.hpp>

#include "Constants.h"

int main()
{
	// create a window & settings
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), "visualgo");
	sf::View view = window.getDefaultView();
	window.setFramerateLimit(144);


	// while the window is kept open
	while (window.isOpen())
	{
		// store and loop through each event
		sf::Event event;
		while (window.pollEvent(event))
		{

			// if closing window
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}

				break;
			}
		}

		// clear frame
		window.clear(sf::Color(20, 20, 20));

		// update

		// render

		// show frame / draw calls
		window.display();
	}

	return 0;
}