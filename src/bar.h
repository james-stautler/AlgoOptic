#ifndef BAR_H
#define BAR_H

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Bar {
    private:
        int height;
        int width;
        int posx;
        int posy;
        sf::Color color;

    public:
        Bar(int height = 0, int width = 0, int posx = 0, int posy = 0, sf::Color color = sf::Color::White);

        void setHeight(int height);
        void setWidth(int width);
        void setX(int posx);
        void setY(int posy);
        void setColor(sf::Color color);

        int getHeight();
        int getWidth();
        int getX();
        int getY();
        sf::Color getColor();
        
};

#endif
