#ifndef BRUSH_H
#define BRUSH_H

#include "../canvas/canvas.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

class Brush
{
public:
	Brush();
	Brush(int _window_width, int _window_height, Canvas* _canvas);

	void set_current_canvas(Canvas* _canvas);
	void set_color(sf::Color _color);

	void draw_pixel   (sf::Vector2i mouse_position);
	void erase_pixel  (sf::Vector2i mouse_position);
	sf::Color pipette (sf::Vector2i mouse_position);

private:
	sf::Vector2i get_pixel_position(sf::Vector2i mouse_position);

	Canvas* current_canvas = nullptr;

	sf::Color current_color = sf::Color::Black;

	int pixel_size    = 10;

	int canvas_width  = 0;
	int canvas_height = 0;

	int window_width  = 0;
	int window_height = 0;
};

#endif 