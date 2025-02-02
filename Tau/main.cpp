#include <SFML/Graphics.hpp>

#include "renderer/renderer.h"
#include "canvas/canvas.h"
#include "brush/brush.h"
#include "ui/slider/slider.h"
#include "ui/palette/palette.h"
#include "fileManager/fileManager.h"

#include <iostream>
#include <string>

#define WINDOW_WIDTH    1920
#define WINDOW_HEIGHT   1080

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
                switch(event->getIf<sf::Event::KeyPressed>()->code)
                {
                    case sf::Keyboard::Key::S:        
                        file_manager.save();
                        break;
                    case sf::Keyboard::Key::O:
                    {  
                        std::string path;
                        std::cout << "Enter path >> ";
                        std::cin  >> path;
                        std::cout << std::endl;
                        file_manager.open(path);
                        break;
                    }
                    case sf::Keyboard::Key::D:
                        brush.set_current_brush(1);
                        break;
                    case sf::Keyboard::Key::E:
                        brush.set_current_brush(2);
                        break;
                    case sf::Keyboard::Key::P:
                        brush.set_current_brush(3);
                        break;
                    case sf::Keyboard::Key::F:
                        brush.set_current_brush(4);
                        break;
                }
            }

            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
            bool is_within_canvas = canvas.contains_pixel(canvas.get_pixel_position(mouse_position).x, canvas.get_pixel_position(mouse_position).y);

            switch (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) ? 1 :
                    sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) ? 2 : 0) 
            {
                case 1: 
                    
                    brush.set_color(palette.get_color(mouse_position));

                    if (is_within_canvas) {
                        if (brush.get_current_brush() == 3)
                        {
                            brush.use(mouse_position, &palette);
                        }
                        else
                        {
                            brush.use(mouse_position);
                        }
                    }
                    break;

                case 2: 
                    if (is_within_canvas) {
                        brush.use(mouse_position, 2);
                    }
                    break;
            }
        }

        renderer.render();
        window.display();
    }
}
