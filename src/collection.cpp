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


void Collection::initial_display(sf::RenderWindow& window, std::vector<sf::RectangleShape> rect) {
    window.sf::RenderWindow::clear(sf::Color::Black);

    for (int i = 0; i < rect.size(); i++) 
    {
        window.draw(rect[i]);
        window.display();
    }
}

void Collection::newDisplay(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect)
{
    window.sf::RenderWindow::clear(sf::Color::Black);
    for (int i = 0; i < rect.size(); i++)
    {   
        window.draw(rect[i]);
    }
    window.display();
}

void Collection::fillAll(std::vector<sf::RectangleShape>& rect)
{
    for (int i = 0; i < rect.size(); i++) 
    {
        rect[i].setFillColor(sf::Color::Green);
    }
}

void Collection::bubbleSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect) 
{
    for (int i = 0; i < this->getQuantity(); i++)
    {
        for (int j = 0; j < this->getQuantity() - i - 1; j++)
        {
            rect[j].setFillColor(sf::Color::Red);
            newDisplay(window, rect);
            if (rect[j].getSize().y >= rect[j + 1].getSize().y)
            {
                int temp = rect[j].getSize().y;
                sf::Vector2f size(5, rect[j + 1].getSize().y);
                rect[j].setSize(size);
                sf::Vector2f size2(5, temp);
                rect[j + 1].setSize(size2);
            }
            rect[j].setFillColor(sf::Color::White);
            rect[j + 1].setFillColor(sf::Color::Red);
        }
    }
}

void insertionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect)
{

}


std::vector<sf::RectangleShape> Collection::convertRect()
{
    std::vector<sf::RectangleShape> rectangles;
    for (int i = 0; i < this->getQuantity(); i++)
    {
        sf::RectangleShape bar;
        sf::Vector2f pos(bars[i].getX(), bars[i].getY());
        sf::Vector2f size(bars[i].getWidth(), bars[i].getHeight());
        bar.setPosition(pos);
        bar.setSize(size);
        bar.setFillColor(bars[i].getColor());
        rectangles.push_back(bar);
    }

    return rectangles;
}

int Collection::getQuantity()
{
    return this->quantity;
}