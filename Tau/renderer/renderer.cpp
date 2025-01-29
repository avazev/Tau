#include "renderer.h"

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
	if (_render_window != nullptr)
	{
		render_window = _render_window;
	}
}

void Renderer::set_current_canvas(Canvas* _canvas)
{
	if (_canvas != nullptr)
	{
		current_canvas =_canvas;

		update();
	}
}

void Renderer::update()
{
	pixel_size    = current_canvas -> get_pixel_size();

	canvas_width  = current_canvas -> get_canvas_width();
    canvas_height = current_canvas -> get_canvas_height();

    pixels_offset = current_canvas -> get_offset();
}

void Renderer::render()
{
	sf::Color** pixels = current_canvas -> get_pixels();

	pixels_offset = current_canvas -> get_offset();

	render_window -> clear(background_color);

	for (int y = 0; y < canvas_height; ++y) 
	{
        for (int x = 0; x < canvas_width; ++x) 
        {
            sf::RectangleShape pixel(sf::Vector2f(pixel_size, pixel_size));

            pixel.setPosition(sf::Vector2f(pixel_size * x + pixels_offset.x, pixel_size * y + pixels_offset.y));
            pixel.setFillColor(pixels[x][y]);

            render_window -> draw(pixel);
        }
    }

    for (auto shape : shapes)
    {
    	render_window -> draw(*shape);
    }

	for (auto ui_element : ui_elements) 
    {
     	render_window -> draw(*ui_element); 
    }
}