#include <SFML/Graphics.hpp>
#include<iostream>
#include <thread>

#include "Constants.h"
#include "Settings.h"
#include "Visualizer.h"
#include "Element.h"

int main()
{
	// create a window & settings
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), "visualgo", sf::Style::Fullscreen);
	window.setFramerateLimit(144);
	window.setVerticalSyncEnabled(true);

	Settings settings(250, Merge);
	Visualizer visualizer(settings);

	visualizer.Randomize();


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



		visualizer.UpdateElements();

		// render
		visualizer.Render(window);

		// show frame / draw calls
		window.display();
	}

	return 0;
}