#pragma once
#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include <iostream>
#include <functional> 
#include <cstddef>
#include "open.hpp"

class Button {
public:
    Button(const sf::String& text, const sf::Font& font, const sf::Vector2f& size, const int x, const int y);
    ~Button() = default;
    void update(sf::RenderWindow& window);
    void setAction(std::function<void()> action);

private:
    sf::Text text;
    sf::RectangleShape shape;
    sf::Vector2f size;
    std::function<void()> action;
};

void openResultWindow(std::string& new_filename);
void openStartWindow();

#endif