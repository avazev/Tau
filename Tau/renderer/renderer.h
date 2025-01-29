#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "../canvas/canvas.h"

class Renderer
{
public:
	Renderer();
	Renderer(sf::RenderTarget* _render_window);
	Renderer(sf::RenderTarget* _render_window, Canvas* _canvas);

	void set_render_target(sf::RenderTarget* _render_window);
	void set_current_canvas(Canvas* _canvas);

	void add_ui_element(sf::VertexArray* _ui_element) { ui_elements.push_back(_ui_element); };
	void add_shape     (sf::RectangleShape* _shape)   { shapes.push_back(_shape); };

	Canvas* get_current_canvas() { return current_canvas; };

	void update();
	void render();

private:
	sf::RenderTarget* render_window  = nullptr;
	Canvas*           current_canvas = nullptr;

	sf::Vector2f pixels_offset;

	std::vector<sf::VertexArray*>    ui_elements;
	std::vector<sf::RectangleShape*> shapes;

	int pixel_size    = 10;

	int canvas_width  = 0;
    int canvas_height = 0;

    sf::Color background_color = sf::Color(50, 50, 50);
};

#endif 
