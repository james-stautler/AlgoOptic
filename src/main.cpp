
#include "collection.h"
#include "bar.h"

const int DISPLAY_HEIGHT = 1080;
const int DISPLAY_WIDTH = 1280;



int main()
{
    sf::RenderWindow window(sf::VideoMode(DISPLAY_WIDTH, DISPLAY_HEIGHT), "Window");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../fonts/want_coffee/want-coffee.ttf"))
    {
        throw("COULD NOT LOAD FONT!");
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    sf::Vector2f pos(50, 800);
    text.setPosition(pos);
    text.setString("CLICK THE MOUSE TO GENERATE NEW DATA SET\n\nPress 1 to perform bubble sort\n\nPress 2 to perform insertion sort\n\nPress 3 to perform merge sort");

    while (window.isOpen()) 
    {
        window.draw(text);

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

                if (event.key.code == sf::Keyboard::Num3)
                {
                    int length = rectangles.size();
                    data.Collection::mergeSort(window, rectangles, 0, length - 1);
                    data.Collection::fillAll(rectangles);
                    data.Collection::newDisplay(window, rectangles);
                }

            }



        }

        
        window.display();

    }

    return 0;
}



