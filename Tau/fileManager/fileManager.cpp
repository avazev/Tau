#include "fileManager.h"
#include <string>
#include <iostream>
#include <filesystem>

FileManager::FileManager()
{
    canvas = nullptr;
}

FileManager::FileManager(Canvas* _canvas)
{
    canvas = _canvas;
}

std::string generate_filename(const std::string& baseName, const std::string& extension) 
{
    std::string fileName = baseName + extension;
    int counter = 1;

    while (std::filesystem::exists(fileName)) 
    {
        fileName = baseName + std::to_string(counter) + extension;
        counter++;
    }

    return fileName;
}

void FileManager::save() 
{
    int canvas_width  = canvas -> get_canvas_width();
    int canvas_height = canvas -> get_canvas_height();

    sf::Color** pixels   = canvas -> get_pixels(); 
    bool** pixel_changed = canvas -> get_pixel_changed(); 

    sf::Image image(sf::Vector2u(canvas_width, canvas_height), sf::Color(0, 0, 0, 0));

    std::cout << canvas_width << " : " << canvas_height << std::endl;

    for (int x = 0; x < canvas_width; x++) 
    {
        for (int y = 0; y < canvas_height; y++) 
        {
            if (!pixel_changed[x][y])
            {
                image.setPixel(sf::Vector2u(x, y), sf::Color(0, 0, 0, 0));
            }
            else
            {
                image.setPixel(sf::Vector2u(x, y), pixels[x][y]);
            }
        }
    }

    std::filesystem::path imagesDir("images");
    
    if (!std::filesystem::exists(imagesDir)) 
    {
        std::filesystem::create_directory(imagesDir);
    }

    std::string filePath = generate_filename("images/image", ".png");

    if (!image.saveToFile(filePath))
        std::cerr << "failed to save image" << std::endl;
    else
        std::cout << "image saved successfully as " << filePath << std::endl;
}

void FileManager::open(const std::string _path)
{
    sf::Image    image(_path);
    sf::Vector2u image_size = image.getSize();

    canvas -> set_canvas_size(image_size.x, image_size.y);

    for (int x = 0; x < image_size.x; x++) 
    {
        for (int y = 0; y < image_size.y; y++) 
        {
            sf::Color pixel_color = image.getPixel(sf::Vector2u(x, y));

            if (pixel_color == sf::Color(0, 0, 0, 0))
            {
                canvas -> erase_pixel(x, y);
            }
            else
            {
                canvas -> draw_pixel(x, y, pixel_color);
            }
        }
    }
}