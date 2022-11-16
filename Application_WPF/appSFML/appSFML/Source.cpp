#include <iostream>
#include "Header.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    window.clear(sf::Color::White);
    
    tslButton b1(10, 10, 80, 30, sf::Color::Black, window);
    b1.setButtonText("Test");
    b1.setFontSize(10);
    b1.render();
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Time delayTime = sf::milliseconds(150);
            if (b1.isClicked()) {
                std::cout << 1 << std::endl;
            }
            sf::sleep(delayTime);
        }

    }

    return 0;
}