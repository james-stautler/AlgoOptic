
#include "collection.h"
#include "bar.h"

const int DISPLAY_HEIGHT = 1080;
const int DISPLAY_WIDTH = 1280;



int main()
{
    sf::RenderWindow window(sf::VideoMode(DISPLAY_WIDTH, DISPLAY_HEIGHT), "Window");
    window.setFramerateLimit(60);
    
    while (window.isOpen()) 
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {   
            Collection data;
            std::vector<sf::RectangleShape> rectangles = data.convertRect();

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {   
                data.Collection::initial_display(window, rectangles);
            }
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Num1)
                {
                    data.Collection::bubbleSort(window, rectangles);
                    data.Collection::fillAll(rectangles);
                    data.Collection::newDisplay(window, rectangles);
                }

                if (event.key.code == sf::Keyboard::Num2)
                {
                    data.Collection::insertionSort(window, rectangles);
                    data.Collection::fillAll(rectangles);
                    data.Collection::newDisplay(window, rectangles);
                }

            }



        }

        
        window.display();

    }

    return 0;
}



