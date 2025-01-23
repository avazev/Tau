#ifndef CANVAS_H
#define CANVAS_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Canvas
{
public:
    Canvas(int _window_width, int _window_height);
    Canvas(int _width, int _height, int _window_width, int _window_height);
    ~Canvas();

    void set_canvas_size(int _width, int _height);
    void update();
    void draw_pixel(int x, int y, sf::Color color);

    int get_pixel_size() { return pixel_size; };

private:
	int window_width;	//  Ширина окна
	int window_height;  //  Высота окна

	int pixel_size = 0; //  Размер пикселя

    int width = 0;  	//  Ширина холста в пикселях
    int height = 0; 	//  Высота холста в пикселях

    sf::Color** pixels = nullptr; 

    void update_pixelsize();
};

#endif
