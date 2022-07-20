#include "bar.h"


Bar::Bar(int height, int width, int posx, int posy, sf::Color color) 
{
    this->height = height;
    this->width = width;
    this->posx = posx;
    this->posy = posy;
    this->color = color;
}

void Bar::setHeight(int height) 
{
    this->height = height;
}

void Bar::setWidth(int width)
{
    this->width = width;
}

void Bar::setX(int posx)
{
    this->posx = posx;
}

void Bar::setY(int posy)
{
    this->posy = posy;
}

void Bar::setColor(sf::Color color)
{
    this->color = color;
}

int Bar::getHeight()
{
    return this->height;
}

int Bar::getWidth()
{
    return this->width;
}

int Bar::getX()
{
    return this->posx;
}

int Bar::getY()
{
    return this->posy;
}

sf::Color Bar::getColor()
{
    return this->color;
}

