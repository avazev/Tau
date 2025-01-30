#include <SFML/Graphics.hpp>

#include "renderer/renderer.h"
#include "canvas/canvas.h"
#include "brush/brush.h"
#include "ui/slider/slider.h"
#include "ui/palette/palette.h"
#include "fileManager/fileManager.h"

#include <iostream>
#include <string>

#define WINDOW_WIDTH	1920
#define WINDOW_HEIGHT	1080

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "Tau");
    window.setFramerateLimit(60);

    unsigned int canvas_size = 64;

    Canvas canvas(WINDOW_HEIGHT, WINDOW_HEIGHT, canvas_size, canvas_size);

    canvas.set_offset(sf::Vector2f((WINDOW_WIDTH - WINDOW_HEIGHT) / 2, 0));

    Renderer renderer(&window, &canvas);

    renderer.update();

    Brush brush(WINDOW_WIDTH, WINDOW_HEIGHT, &canvas);

    Palette palette(sf::Vector2f(30.0f, 30.0f));
    palette.add_to_renderer(&renderer);

    FileManager file_manager(&canvas);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (event->is<sf::Event::KeyPressed>())
            {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::S)
                {
                    file_manager.save();
                }
                else if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::O)
                {
                    std::string path;
                    std::cout << "Enter path >> ";
                    std::cin  >> path;
                    std::cout << std::endl;

                    file_manager.open(path);
                }
            }


            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                brush.set_color(palette.get_color(sf::Mouse::getPosition(window)));
                brush.draw_pixel(sf::Mouse::getPosition(window));
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
            {
                brush.erase_pixel(sf::Mouse::getPosition(window));
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
            {
                sf::Color new_color = brush.pipette(sf::Mouse::getPosition(window));

                brush.set_color  (new_color);
                palette.set_color(new_color);
            }
        }

        renderer.render();

        window.display();
    }
}
