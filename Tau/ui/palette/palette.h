#ifndef PALETTE_H
#define PALETTE_H

#include <SFML/Graphics/Color.hpp>
#include "../slider/slider.h"

class Palette
{
public:
	sf::Color get_color() { return current_color; };

private:
	sf::Color current_color;
};

#endif