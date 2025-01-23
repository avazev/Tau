#include "canvas.h"
#include <iostream>

Canvas::Canvas(int _window_width, int _window_height) 
{
    set_canvas_size(64, 64);

    window_width  = _window_width;
    window_height = _window_height;

    update_pixelsize();
}

Canvas::Canvas(int _width, int _height, int _window_width, int _window_height) 
{
    set_canvas_size(_width, _height);

    window_width  = _window_width;
    window_height = _window_height;

    update_pixelsize();
}

Canvas::~Canvas() 
{
    if (pixels) 
    {
        for (int i = 0; i < height; ++i) 
        {
            delete[] pixels[i]; 
        }
        delete[] pixels; 
    }
}

void Canvas::set_canvas_size(int _width, int _height) 
{
    if (pixels) 
    {
        for (int i = 0; i < height; ++i) 
        {
            delete[] pixels[i]; 
        }
        delete[] pixels; 
    }

    width = _width;
    height = _height;

    pixels = new sf::Color*[height]; 
    
    for (int i = 0; i < height; ++i) 
    {
        pixels[i] = new sf::Color[width]; 
    }
}

void Canvas::draw_pixel(int x, int y, sf::Color color) 
{
    if (x >= 0 && x < width && y >= 0 && y < height) 
    {
        pixels[y][x] = color; 
    }
}

void Canvas::update_pixelsize()
{
	if (width != 0)
	{
		pixel_size = window_width / width ;
	}

	else
	{
		pixel_size = 0;
	}
}