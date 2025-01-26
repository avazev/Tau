#include "renderer.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Renderer::Renderer(sf::RenderTarget* _render_window)
{
	set_render_target(_render_window);
}

Renderer::Renderer(sf::RenderTarget* _render_window, Canvas* _canvas)
{
	set_render_target(_render_window);
	set_current_canvas(_canvas);
}

void Renderer::set_render_target(sf::RenderTarget* _render_window)
{
	render_window = _render_window;
}

void Renderer::set_current_canvas(Canvas* _canvas)
{
	current_canvas =_canvas;
}

void Renderer::update()
{
	pixel_size    = current_canvas->get_pixel_size();

	canvas_width  = current_canvas->get_canvas_width();
    canvas_height = current_canvas->get_canvas_height();
}

void Renderer::render()
{
	sf::Color** pixels = current_canvas->get_pixels();

	for (int y = 0; y < canvas_height; ++y) 
	{
        for (int x = 0; x < canvas_width; ++x) 
        {
            sf::RectangleShape pixel(sf::Vector2f(pixel_size, pixel_size));

            pixel.setPosition(sf::Vector2f(pixel_size * x, pixel_size * y));
            pixel.setFillColor(pixels[x][y]);

            render_window->draw(pixel);
        }
    }
}