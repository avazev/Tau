#include "slider.h"

Slider::Slider()
{
	set_position(sf::Vector2f(0.0f, 0.0f));
	set_size    (sf::Vector2f(1.0f, 1.0f));
}

Slider::Slider(sf::Vector2f _size, sf::Vector2f _position)
{
	set_size(_size);
	set_position(_position);
}

Slider::Slider(sf::Vector2f _size, sf::Vector2f _position, sf::Color _color_left, sf::Color _color_right)
{
	set_size(_size);
	set_position(_position);
	set_color(_color_left, _color_right);
}

Slider::Slider(sf::Vector2f _size, sf::Vector2f _position, sf::Color _color_left, sf::Color _color_right, int _default_value)
{
	set_size(_size);
	set_position(_position);
	set_color(_color_left, _color_right);

	value = _default_value;
}

void Slider::set_color(sf::Color _color_left, sf::Color _color_right)
{
	color_left  = _color_left;
	color_right = _color_right;

	init_slider_shape();
}

void Slider::set_position(sf::Vector2f _position)
{
	position = _position;

	init_slider_shape();
}

void Slider::set_size(sf::Vector2f _size)
{
	size = _size;

	init_slider_shape();
}

int Slider::get_value(sf::Vector2i mouse_position)
{
	if (contains(mouse_position))
	{
		if (mouse_position.x < position.x)
		{
			return 0;
		}
		else if (mouse_position.x > position.x + size.x) 
    	{
        	return 255;
    	}

		if (static_cast<int>(size.x) % 255 == 0.0f)
		{
			value = mouse_position.x - position.x;
		}
		else 
		{
			int mouse_position_in_slider = mouse_position.x - position.x;
			float percentage = mouse_position_in_slider / size.x;

			float value_float = 255 * percentage;
		}
	}
	return value;
}

bool Slider::contains(sf::Vector2i mouse_position)
{
    if (mouse_position.x >= position.x - 50 && mouse_position.x <= position.x + size.x + 50 &&
        mouse_position.y >= position.y && mouse_position.y <= position.y + size.y) 
    {
        return true;
    }

    return false;
}

void Slider::init_slider_shape()
{
    slider_shape[0].position = sf::Vector2f(position.x, position.y);                   // upper left 
    slider_shape[1].position = sf::Vector2f(position.x + size.x, position.y);          // upper right 
    slider_shape[2].position = sf::Vector2f(position.x + size.x, position.y + size.y); // lower right
    slider_shape[3].position = sf::Vector2f(position.x, position.y + size.y);          // lower left 

    for (int i = 0; i < 4; ++i) 
    {
        float factor = (i == 0 || i == 3) ? 0.0f : 1.0f; 

        slider_shape[i].color = sf::Color(
            static_cast<int>((1.0f - factor) * color_left.r + factor * color_right.r),
            static_cast<int>((1.0f - factor) * color_left.g + factor * color_right.g),
            static_cast<int>((1.0f - factor) * color_left.b + factor * color_right.b)
        );
    }
}