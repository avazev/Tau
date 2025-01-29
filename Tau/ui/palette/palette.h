#ifndef PALETTE_H
#define PALETTE_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "../slider/slider.h"
#include "../../renderer/renderer.h"

class Palette
{
public:
	Palette();
	Palette(sf::Vector2f _position);

	void add_to_renderer(Renderer* renderer);

	void set_example_position(sf::Vector2f _position);
	void set_example_size(sf::Vector2f _size);

	sf::Vector2f get_position() { return example_position; };
	sf::Color get_color(sf::Vector2i _mouse_position);

	void set_color(sf::Color _color);

private:
	void palette_init();

	Slider sliders[4];

	sf::RectangleShape color_example;
	sf::Color current_color = sf::Color(0, 0, 0, 255);

	sf::Vector2f example_position;
	sf::Vector2f example_size{255.0f, 255.0f};

	sf::Vector2f slider_size = example_size;

	float slider_interval = 40.0f;
};

#endif