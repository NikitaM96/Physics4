#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Go Physics!!");

	sf::Font font;
	sf::Text text;

	sf::CircleShape shape(.5f);
	shape.setFillColor(sf::Color::Green);
	

	sf::Vector2f velocity(0, 1);
	sf::Vector2f position(400, 400);

	sf::Vector2f gravity(0.0f, 9.8f);

	//For Line
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(1, 700)),
		sf::Vertex(sf::Vector2f(800, 700))
	};

	if (!font.loadFromFile("./Resources/gothic.ttf"))
	{

	}

	//sf::Event event;

	sf::Clock clock;

	const float FPS = 60.0f;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	clock.restart();

	while (window.isOpen())
	{
		//read key board input
		
		sf::Event event;
		
		//get time since last update and reset clock
		timeSinceLastUpdate += clock.restart();

		//update every 69th of sec
		if (timeSinceLastUpdate > timePerFrame)
		{
			window.clear();

			shape.setPosition(position);
			window.draw(shape);
			window.draw(line, 2, sf::Lines);
			window.display();

			timeSinceLastUpdate = sf::Time::Zero;
		}
		//return 0;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				position = position + (velocity * ((int)timeSinceLastUpdate));
			}
		}
	}

}