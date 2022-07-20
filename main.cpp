
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>

const int DISPLAY_HEIGHT = 720;
const int DISPLAY_WIDTH = 1280;

int n = 128;

struct Rectangle {

    int height;
    int width;

    int posx;
    int posy;

    sf::Color color = sf::Color::White;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(DISPLAY_WIDTH, DISPLAY_HEIGHT), "Window");
    window.setFramerateLimit(60);

    while (window.isOpen()) 
    {
        sf::Event event;

        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                window.sf::RenderWindow::clear(sf::Color::Black);

                Rectangle bars[n];

                for (int i = 0; i < n; i++) {
                    Rectangle bar;
                    bar.posx = 10 * i;
                    bar.posy = 0;
                    bar.width = 5;
                    bar.height = 1 + (rand() % 700);
                    bars[i] = bar;
                }

                for (int i = 0; i < n; i++) 
                {
                    sf::RectangleShape bar;
                    sf::Vector2f pos(bars[i].posx, bars[i].posy);
                    sf::Vector2f size(bars[i].width, bars[i].height);
                    bar.setPosition(pos);
                    bar.setSize(size);
                    bar.setFillColor(bars[i].color);
                    window.draw(bar);
                    window.display();
                }
                
            } 
        }

        
        window.display();

    }

    return 0;
}