#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../canvas/canvas.h"

class Renderer
{
public:
	Renderer();
	Renderer(sf::RenderTarget* _render_window);
	Renderer(sf::RenderTarget* _render_window, Canvas* _canvas);

	void set_render_target(sf::RenderTarget* _render_window);
	void set_current_canvas(Canvas* _canvas);

	Canvas* get_current_canvas() { return current_canvas; };

	void update();
	void render();

private:
	sf::RenderTarget* render_window = nullptr;

	Canvas* current_canvas = nullptr;

	int pixel_size    = 10;

	int canvas_width  = 0;
    int canvas_height = 0;
};

#endif 
