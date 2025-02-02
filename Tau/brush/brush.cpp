#include "brush.h"

#include <iostream>
#include <queue>
#include <stack>  
#include <set>
#include <queue> 

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

sf::Vector2i Brush::get_pixel_position(sf::Vector2i _mouse_position)
{
	int pixel_size = current_canvas -> get_pixel_size();
	sf::Vector2f offset = current_canvas -> get_offset();

	sf::Vector2i pixel_position;

	pixel_position.x = (_mouse_position.x - offset.x) / pixel_size;
	pixel_position.y = (_mouse_position.y - offset.y) / pixel_size;

	return pixel_position;
} 



void Brush::use(sf::Vector2i _mouse_position)
{
	switch (current_brush)
	{
	    case 1:
	    	draw_pixel(_mouse_position);
	    	break;

	    case 2:
	    	erase_pixel(_mouse_position);
	    	break;

	    case 4:
	    	fill(_mouse_position);
	    	break;
	}
}

void Brush::use(sf::Vector2i _mouse_position, unsigned int _brush_number)
{  
	switch(_brush_number)
    {
		case 2:
			erase_pixel(_mouse_position);
			break;
    }
}

void Brush::use(sf::Vector2i _mouse_position, Palette* _palette)
{
	sf::Color new_color = pipette(_mouse_position);

	set_color(new_color);
	_palette -> set_color(new_color);
}



void Brush::draw_pixel(sf::Vector2i _mouse_position)
{
    sf::Vector2i pixel_position = get_pixel_position(_mouse_position);

    if (current_canvas->contains_pixel(pixel_position.x, pixel_position.y)) 
    {
        current_canvas->draw_pixel(pixel_position.x, pixel_position.y, current_color);
    }
}

void Brush::erase_pixel(sf::Vector2i _mouse_position)
{
    sf::Vector2i pixel_position = get_pixel_position(_mouse_position);

    if (current_canvas->contains_pixel(pixel_position.x, pixel_position.y)) 
    {
        current_canvas->erase_pixel(pixel_position.x, pixel_position.y);
    }
}


struct Vector2Comparator 
{
    bool operator()(const sf::Vector2<int>& lhs, const sf::Vector2<int>& rhs) const 
    {
        return (lhs.x < rhs.x) || (lhs.x == rhs.x && lhs.y < rhs.y);
    }
};

void Brush::fill(sf::Vector2i _mouse_position)
{
    sf::Vector2i pixel_position = get_pixel_position(_mouse_position);
    sf::Color target_color = current_canvas->get_pixel_color(pixel_position.x, pixel_position.y);

    if (!current_canvas->contains_pixel(pixel_position.x, pixel_position.y) || target_color == current_color) return;

    sf::Vector2i canvas_size = sf::Vector2i(current_canvas->get_canvas_width(), current_canvas->get_canvas_height());
    std::stack<sf::Vector2i> pixels_to_fill;
    std::set<sf::Vector2<int>, Vector2Comparator> visited;

    pixels_to_fill.push(pixel_position);

    while (!pixels_to_fill.empty())
    {
        sf::Vector2i current_pixel = pixels_to_fill.top();
        pixels_to_fill.pop();

        if (visited.find(current_pixel) != visited.end()) continue;
        visited.insert(current_pixel);

        current_canvas->draw_pixel(current_pixel.x, current_pixel.y, current_color);

        std::vector<sf::Vector2i> neighbors = {
            {current_pixel.x + 1, current_pixel.y},
            {current_pixel.x - 1, current_pixel.y},
            {current_pixel.x, current_pixel.y + 1},
            {current_pixel.x, current_pixel.y - 1}
        };

        for (const auto& neighbor : neighbors)
        {
            if (current_canvas->contains_pixel(neighbor.x, neighbor.y) && 
                visited.find(neighbor) == visited.end() && 
                current_canvas->get_pixel_color(neighbor.x, neighbor.y) == target_color)
            {
                pixels_to_fill.push(neighbor);
            }
        }
    }
}


sf::Color Brush::pipette(sf::Vector2i _mouse_position)
{
    sf::Vector2i pixel_position = get_pixel_position(_mouse_position);

    if (current_canvas->contains_pixel(pixel_position.x, pixel_position.y)) {
        sf::Color pixel_color = current_canvas->get_pixel_color(pixel_position.x, pixel_position.y);
        current_color = pixel_color;
        return current_color;
    }

    return current_color;
}
