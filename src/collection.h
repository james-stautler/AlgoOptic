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
        void insertionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect);
        void merge(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect, int p, int q, int r);
        void mergeSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect, int p, int r);
        void newDisplay(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rect);
        void fillAll(std::vector<sf::RectangleShape>& rect);
        std::vector<sf::RectangleShape> convertRect();


};

#endif