#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "../canvas/canvas.h"
#include <SFML/Graphics/Image.hpp> 
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>  

#include <iostream>
#include <filesystem>

class FileManager
{
public:
	FileManager();
	FileManager(Canvas* _canvas);

	void save();

private:
	Canvas* canvas;
};

#endif
