#ifndef SLIDER_H
#define SLIDER_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class Slider
{
public:
	Slider();
	Slider(sf::Vector2f _size, sf::Vector2f _position);
	Slider(sf::Vector2f _size, sf::Vector2f _position, sf::Color _color_left, sf::Color _color_right);

	void set_color   (sf::Color _color_left, sf::Color _color_right);
	void set_position(sf::Vector2f _position);
	void set_size    (sf::Vector2f _size);

	sf::Vector2f get_position() { return position; };
	sf::Vector2f get_size    () { return size; };

	int get_value(sf::Vector2i mouse_position);
    sf::VertexArray* get_slider_shape() { return &slider_shape; };


private:
	int value = 0;

	sf::Vector2f position{0.0f, 0.0f};
	sf::Vector2f size    {1.0f, 1.0f};

	sf::Color color_left {0, 0, 0, 0};
	sf::Color color_right{255, 255, 255, 255};

	sf::VertexArray slider_shape{sf::Quads, 4};

	bool contains(sf::Vector2i mouse_position);
	void init_slider_shape();
};

#endif 