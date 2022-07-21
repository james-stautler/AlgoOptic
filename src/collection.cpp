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

            if (j == this->getQuantity() - i - 2)
            {
                rect[j].setFillColor(sf::Color::White);
                rect[j + 1].setFillColor(sf::Color::White);
            } else
            {
                rect[j].setFillColor(sf::Color::White);
                rect[j + 1].setFillColor(sf::Color::Red);
            }

        }
    }
}

void Collection::insertionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect)
{
    for (int i = 1; i < rect.size(); i++)
    {
        int key = rect[i].getSize().y;
        int j = i - 1;

        rect[i].setFillColor(sf::Color::Red);
        newDisplay(window, rect);

        while (j >= 0 && rect[j].getSize().y > key)
        {
            sf::Vector2f size(5, rect[j].getSize().y);
            rect[j + 1].setSize(size);
            rect[j].setFillColor(sf::Color::Red);
            rect[j + 1].setFillColor(sf::Color::White);
            j -= 1;
            newDisplay(window, rect);
        }

        if (j < 0) 
        {
            rect[0].setFillColor(sf::Color::White);
        } else
        {
            rect[j].setFillColor(sf::Color::White);
        }

        sf::Vector2f size(5, key);
        rect[j + 1].setSize(size);
        rect[j + 1].setFillColor(sf::Color::White);
        newDisplay(window, rect);
    }
}


void Collection::merge(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect, int p, int q, int r)
{
    int n1, n2;

    n1 = q - p + 1;
    n2 = r - q;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = rect[p + i].getSize().y;
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = rect[q + j + 1].getSize().y;
    }

    int i = 0;
    int j = 0;
    int k = p;

    for (k; i < n1 && j < n2; k++)
    {
        if (L[i] < R[j])
        {
            sf::Vector2f size(5, L[i++]);
            rect[k].setSize(size);
        } else
        {
            sf::Vector2f size(5, R[j++]);
            rect[k].setSize(size);
        }
    }

    while (i < n1)
    {
        sf::Vector2f size(5, L[i++]);
        rect[k++].setSize(size);
    }

    while (j < n2)
    {
        sf::Vector2f size(5, R[j++]);
        rect[k++].setSize(size);
    }


}

void Collection::mergeSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(window, rect, p, q);
        mergeSort(window, rect,  q + 1, r);
        merge(window, rect, p, q, r);

    }
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