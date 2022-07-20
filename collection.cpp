#include "collection.h"

Collection::Collection()
{
    for (int i = 0; i < 128; i++) 
    {
        Bar bar;
        bar.setHeight(1 + (rand() % 700));
        bar.setWidth(5);
        bar.setX(10 * i);
        bar.setY(0);
        bar.setColor(sf::Color::White);
        bars.push_back(bar);
        this->quantity += 1;
    }
}


void Collection::display(sf::RenderWindow& window) {
    window.sf::RenderWindow::clear(sf::Color::Black);

    for (int i = 0; i < 128; i++) 
    {
        sf::RectangleShape bar;
        sf::Vector2f pos(bars[i].getX(), bars[i].getY());
        sf::Vector2f size(bars[i].getWidth(), bars[i].getHeight());
        bar.setPosition(pos);
        bar.setSize(size);
        bar.setFillColor(bars[i].getColor());
        window.draw(bar);
        window.display();
    }
}


int Collection::getQuantity(int quantity)
{
    return this->quantity;
}