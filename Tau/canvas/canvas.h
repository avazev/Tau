#ifndef CANVAS_H
#define CANVAS_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

class Canvas
{
public:
    Canvas();
    Canvas(int _window_width, int _window_height);
    Canvas(int _window_width, int _window_height, int _canvas_width, int _canvas_height);
    
    ~Canvas();

    void draw_pixel (int x, int y, sf::Color color);
    void erase_pixel(int x, int y);

    void set_canvas_size(int _canvas_width, int _canvas_height);
    void set_empty_color(sf::Color _color) { empty_color = _color; };

    void set_offset(sf::Vector2f _offset) { offset = _offset; };

    sf::Color** get_pixels()   { return pixels; };
    bool** get_pixel_changed() { return pixel_changed; };
  
    int get_pixel_size()      { return pixel_size; };
    
    int get_canvas_width()    { return canvas_width; };
    int get_canvas_height()   { return canvas_height; };

    sf::Vector2i get_pixel_position(sf::Vector2i mouse_position);

    bool contains_pixel(int x, int y);

    sf::Color get_pixel_color(int x, int y) { return pixels[x][y]; };

    sf::Vector2f get_offset() { return offset; };

private:
	int window_width;	     //  Ширина окна
	int window_height;       //  Высота окна

	int pixel_size    = 10;  //  Размер пикселя

    int canvas_width  = 32;  //  Ширина холста в пикселях
    int canvas_height = 32;  //  Высота холста в пикселях

    sf::Vector2f offset{0.0f, 0.0f};

    sf::Color empty_color = sf::Color::White;

    sf::Color** pixels = nullptr; 
    bool** pixel_changed = nullptr; 

    void update_pixelsize();
};

#endif
