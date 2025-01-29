#include "canvas.h"
#include <iostream>

Canvas::Canvas(int _window_width, int _window_height) 
{
    set_canvas_size(64, 64);

    window_width  = _window_width;
    window_height = _window_height;

    update_pixelsize();
}

Canvas::Canvas(int _window_width, int _window_height, int _canvas_width, int _canvas_height) 
{
    set_canvas_size(_canvas_width, _canvas_height);

    window_width  = _window_width;
    window_height = _window_height;

    update_pixelsize();
}

Canvas::~Canvas() 
{
    if (pixels) 
    {
        for (int i = 0; i < canvas_height; ++i) 
        {
            delete[] pixels[i]; 
            delete[] pixel_changed[i];
        }
        delete[] pixels; 
        delete[] pixel_changed;
    }
}

void Canvas::set_canvas_size(int _canvas_width, int _canvas_height) 
{
    if (pixels) 
    {
        for (int i = 0; i < canvas_height; ++i) 
        {
            delete[] pixels[i]; 
            delete[] pixel_changed[i];
        }
        delete[] pixels; 
        delete[] pixel_changed;
    }

    canvas_width = _canvas_width;
    canvas_height = _canvas_height;

    pixels = new sf::Color*[canvas_height]; 
    pixel_changed = new bool*[canvas_width];
    
    for (int i = 0; i < canvas_height; ++i) 
    {
        pixels[i] = new sf::Color[canvas_width]; 
        pixel_changed[i] = new bool[canvas_height];
    }

    for (int i = 0; i < canvas_height; ++i) 
    {
        for (int j = 0; j < canvas_width; ++j) 
        {
            pixels[i][j] = sf::Color::White;
            pixel_changed[i][j] = false;
        }
    }
}

void Canvas::draw_pixel(int x, int y, sf::Color color) 
{
    if (x >= 0 && x < canvas_width && y >= 0 && y < canvas_height) 
    {
        pixels[x][y] = color; 
        pixel_changed[x][y] = true;
    }
}

void Canvas::erase_pixel(int x, int y)
{
    if (x >= 0 && x < canvas_width && y >= 0 && y < canvas_height) 
    {
        pixels[x][y] = empty_color; 
        pixel_changed[x][y] = false;
    }
}

void Canvas::update_pixelsize()
{
	if (canvas_width != 0)
	{
		pixel_size = window_width / canvas_width ;
	}

	else
	{
		pixel_size = 0;
	}
}