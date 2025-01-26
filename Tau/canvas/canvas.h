#ifndef CANVAS_H
#define CANVAS_H

#include <SFML/Graphics/Color.hpp>

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

    sf::Color** get_pixels()  { return pixels; };
  
    int get_pixel_size()      { return pixel_size; };
  
    int get_canvas_width()    { return canvas_width; };
    int get_canvas_height()   { return canvas_height; };

private:
	int window_width;	     //  Ширина окна
	int window_height;       //  Высота окна

	int pixel_size    = 10;  //  Размер пикселя

    int canvas_width  = 32;  //  Ширина холста в пикселях
    int canvas_height = 32;  //  Высота холста в пикселях

    sf::Color empty_color = sf::Color(0, 0, 0, 0);

    sf::Color** pixels = nullptr; 

    void update_pixelsize();
};

#endif
