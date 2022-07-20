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
        void display(sf::RenderWindow& window);
        int getQuantity(int quantity);

};

#endif