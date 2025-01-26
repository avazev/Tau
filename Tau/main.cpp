#include <SFML/Graphics.hpp>

#include "renderer/renderer.h"
#include "canvas/canvas.h"

#include <iostream>

#define WINDOW_WIDTH	1600
#define WINDOW_HEIGHT	1200

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tau");

    Canvas canvas(32, 32, WINDOW_WIDTH, WINDOW_HEIGHT);
    std::cout << "new canvas created" << std::endl;

    canvas.draw_pixel(22, 12, sf::Color::Red);

    Renderer renderer(&window, &canvas);
    std::cout << "renderer initialized" << std::endl;

    renderer.update();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        renderer.render();

        window.display();
    }
}
