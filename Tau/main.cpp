#include <SFML/Graphics.hpp>

#include "renderer/renderer.h"
#include "canvas/canvas.h"
#include "brush/brush.h"
#include "ui/slider/slider.h"

#include <iostream>

#define WINDOW_WIDTH	1600
#define WINDOW_HEIGHT	1200

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tau");

    Canvas canvas_r(WINDOW_WIDTH, WINDOW_HEIGHT, 32, 32);
    std::cout << "canvas_r created" << std::endl;

    Renderer renderer(&window, &canvas_r);
    std::cout << "renderer initialized" << std::endl;

    renderer.update();

    Brush brush(WINDOW_WIDTH, WINDOW_HEIGHT, &canvas_r);
    std::cout << "brush initialized" << std::endl;

    brush.set_color(sf::Color::White);

    Slider slider_r(sf::Vector2f(255.0f, 20.0f), sf::Vector2f(30.0f, 30.0f), sf::Color(0, 0, 0, 255), sf::Color(255, 0, 0 , 255));

    renderer.add_ui_element(slider_r.get_slider_shape());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::C)
                {
                    int r, g, b, a;

                    std::cin >> r;
                    std::cin >> g;
                    std::cin >> b;
                    std::cin >> a;

                    brush.set_color(sf::Color(r, g, b, a));
                }
            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                brush.draw_pixel(sf::Mouse::getPosition(window));
                std::cout << slider_r.get_value(sf::Mouse::getPosition(window)) << std::endl;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                brush.erase_pixel(sf::Mouse::getPosition(window));
            }
        }

        renderer.render();

        window.display();
    }
}
