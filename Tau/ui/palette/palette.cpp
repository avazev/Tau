#include "palette.h"

#include <iostream>

Palette::Palette()
{
	set_example_position(sf::Vector2f(0.0f, 0.0f));
	palette_init();
}

Palette::Palette(sf::Vector2f _position)
{
	set_example_position(_position);
	palette_init();
}

void Palette::add_to_renderer(Renderer* renderer)
{
	renderer -> add_shape(&color_example);

	renderer -> add_ui_element(sliders[0].get_slider_shape());
	renderer -> add_ui_element(sliders[1].get_slider_shape());
	renderer -> add_ui_element(sliders[2].get_slider_shape());
	renderer -> add_ui_element(sliders[3].get_slider_shape());
}

void Palette::set_example_position(sf::Vector2f _position)
{
	example_position = _position;

	// update positions of all elements
}

void Palette::palette_init()
{
	color_example.setPosition(example_position);
	color_example.setSize    (example_size);

	slider_size.x = example_size.x;
	slider_size.y = slider_size.x / 8;

	sliders[0] = Slider(slider_size, 
						sf::Vector2f(example_position.x, 
									 example_position.y + example_size.y + slider_interval),
						sf::Color(0, 0, 0),
						sf::Color(255, 0, 0),
						0);

	sliders[1] = Slider(slider_size, 
						sf::Vector2f(example_position.x, 
									 example_position.y + example_size.y + slider_interval * 2),
						sf::Color(0, 0, 0),
						sf::Color(0, 255, 0),
						0);

	sliders[2] = Slider(slider_size, 
						sf::Vector2f(example_position.x, 
									 example_position.y + example_size.y + slider_interval * 3),
						sf::Color(0, 0, 0),
						sf::Color(0, 0, 255),
						0);

	sliders[3] = Slider(slider_size, 
						sf::Vector2f(example_position.x, 
									 example_position.y + example_size.y + slider_interval * 4),
						sf::Color(0, 0, 0),
						sf::Color(255, 255, 255, 255),
						255);
}

sf::Color Palette::get_color(sf::Vector2i _mouse_position)
{
	current_color = sf::Color(sliders[0].get_value(_mouse_position),
	                 		  sliders[1].get_value(_mouse_position),
	                 		  sliders[2].get_value(_mouse_position), 
	                   		  sliders[3].get_value(_mouse_position));

	color_example.setFillColor(current_color);

	return sf::Color(current_color);
}

void Palette::set_color(sf::Color _color)
{
	current_color = _color;

	color_example.setFillColor(current_color);

	sliders[0].set_value(_color.r);
    sliders[1].set_value(_color.g);
	sliders[2].set_value(_color.b);
    sliders[3].set_value(_color.a);
}