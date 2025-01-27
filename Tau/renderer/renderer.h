#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "../canvas/canvas.h"

class Renderer
{
public:
	Renderer();
	Renderer(sf::RenderTarget* _render_window);
	Renderer(sf::RenderTarget* _render_window, Canvas* _canvas);

	void set_render_target(sf::RenderTarget* _render_window);
	void set_current_canvas(Canvas* _canvas);

	void add_ui_element(sf::VertexArray* ui_element) { ui_elements.push_back(ui_element); };

	Canvas* get_current_canvas() { return current_canvas; };

	void update();
	void render();

private:
	sf::RenderTarget* render_window  = nullptr;
	Canvas*           current_canvas = nullptr;

	std::vector<sf::VertexArray*> ui_elements;

	int pixel_size    = 10;

	int canvas_width  = 0;
    int canvas_height = 0;
};

#endif 
