#include <iostream>
#include <armadillo>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <cmath>


int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML kaleidoscope");
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type){

				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		// window.clear();
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for(size_t i = 0; i < 6; i++)
			{
				float rotation = 1/3 * M_PI * i;
				sf::CircleShape s(10);
				s.setFillColor(sf::Color::White);
				s.setOrigin(s.getRadius(), s.getRadius());
				auto temp = sf::Vector2f(sf::Mouse::getPosition(window));
				arma::vec2 pos = {temp.x, temp.y};
				arma::mat22 rot = { {std::cos(rotation), -std::sin(rotation)}, 
					{std::sin(rotation), std::cos(rotation)}};
				auto newPos = rot*pos;

				std::cout << newPos << std::endl;
				// auto converted = sf::Vector2f(newPos[0], newPos[1]);
				// s.setPosition(converted);
				window.draw(s);
			}
		}
		
		window.display();
	}
}
