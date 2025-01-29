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
	Slider(sf::Vector2f _size, sf::Vector2f _position, sf::Color _color_left, sf::Color _color_right, int _default_value);

	void set_color   (sf::Color _color_left, sf::Color _color_right);
	void set_position(sf::Vector2f _position);
	void set_size    (sf::Vector2f _size);

	sf::Vector2f get_position() { return position; };
	sf::Vector2f get_size    () { return size; };

	int get_value(sf::Vector2i mouse_position);
    sf::VertexArray* get_slider_shape() { return &slider_shape; };


private:
	int value = 255;

	sf::Vector2f position;
	sf::Vector2f size;

	sf::Color color_left {0, 0, 0, 0};
	sf::Color color_right{255, 255, 255, 255};

	sf::VertexArray slider_shape{sf::PrimitiveType::TriangleFan, 4};

	bool contains(sf::Vector2i mouse_position);
	void init_slider_shape();
};

#endif 