#ifndef COLLECTION_H
#define COLLECTION_H

#include "bar.h"
#include <vector>

class Collection {
    private:
        std::vector<Bar> bars;
        int quantity = 0;

    public:
        Collection();
        void initial_display(sf::RenderWindow& window, std::vector<sf::RectangleShape> rect);
        int getQuantity();
        void bubbleSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect);
        void newDisplay(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect);
        void fillAll(std::vector<sf::RectangleShape>& rect);
        std::vector<sf::RectangleShape> convertRect();


};

#endif