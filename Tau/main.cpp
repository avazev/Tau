#include <SFML/Graphics.hpp>
#include "canvas/canvas.h"
#include <iostream>

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tau");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Canvas canvas(128, 128);
    std::cout << "new canvas created" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
