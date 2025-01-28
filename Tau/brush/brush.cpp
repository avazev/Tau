#include "brush.h"

#include <iostream>

Brush::Brush(int _window_width, int _window_height, Canvas* _canvas)
{
	set_current_canvas(_canvas);

	window_width  = _window_width;
	window_height = _window_height;
}

void Brush::set_current_canvas(Canvas* _canvas)
{
	if (_canvas != nullptr)
	{
		current_canvas = _canvas;
	}
}

void Brush::set_color(sf::Color _color)
{
	current_color = _color;
}

void Brush::draw_pixel(sf::Vector2i mouse_position)
{
	sf::Vector2i pixel_position = get_pixel_position(mouse_position);

	current_canvas -> draw_pixel(pixel_position.x, pixel_position.y, current_color);
}

void Brush::erase_pixel(sf::Vector2i mouse_position)
{
	sf::Vector2i pixel_position = get_pixel_position(mouse_position);

	current_canvas -> erase_pixel(pixel_position.x, pixel_position.y);
}

sf::Vector2i Brush::get_pixel_position(sf::Vector2i mouse_position)
{
	int pixel_size = current_canvas -> get_pixel_size();

	sf::Vector2i pixel_position;

	pixel_position.x = mouse_position.x / pixel_size;
	pixel_position.y = mouse_position.y / pixel_size;

	return pixel_position;
} 