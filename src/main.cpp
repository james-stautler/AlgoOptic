
#include "collection.h"
#include "bar.h"

const int DISPLAY_HEIGHT = 720;
const int DISPLAY_WIDTH = 1280;


int main()
{
    sf::RenderWindow window(sf::VideoMode(DISPLAY_WIDTH, DISPLAY_HEIGHT), "Window");
    window.setFramerateLimit(60);

    while (window.isOpen()) 
    {
        sf::Event event;
        bool data_displayed = false;

        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                Collection data;
                data.Collection::display(window);
                data_displayed = true;
            }

            if (event.type == sf::Event::KeyPressed && data_displayed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    // place sorting and update function here
                }
            }
            


        }

        
        window.display();

    }

    return 0;
}

