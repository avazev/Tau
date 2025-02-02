//-------BRUSHES-------\\
//                     \\
// 1. Draw   pixels    \\
// 2. Eraser           \\
// 3. Pipette          \\
// 4. Fill             \\
//                     \\
//---------------------\\


#ifndef BRUSH_H
#define BRUSH_H

#include "../canvas/canvas.h"
#include "../ui/palette/palette.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

class Brush
{
public:
	Brush();
	Brush(int _window_width, int _window_height, Canvas* _canvas);

	void set_current_canvas(Canvas* _canvas);
	void set_color(sf::Color _color);

	unsigned int get_current_brush() { return current_brush; };

	void set_current_brush(unsigned int _brush_number) { current_brush = _brush_number; };

	void      use(sf::Vector2i _mouse_position);
	void      use(sf::Vector2i _mouse_position, unsigned int _brush_number);
	void      use(sf::Vector2i _mouse_position, Palette* _palette);

private:
	sf::Vector2i get_pixel_position(sf::Vector2i mouse_position);

	Canvas* current_canvas = nullptr;

	sf::Color current_color = sf::Color::Black;

	unsigned int current_brush = 1;

	int pixel_size    = 10;

	int canvas_width  = 0;
	int canvas_height = 0;

	int window_width  = 0;
	int window_height = 0;

	void      draw_pixel   	   (sf::Vector2i _mouse_position);
	void      erase_pixel  	   (sf::Vector2i _mouse_position);
	void      fill		   	   (sf::Vector2i _mouse_position);
	sf::Color pipette  	       (sf::Vector2i _mouse_position);
};

#endif 
