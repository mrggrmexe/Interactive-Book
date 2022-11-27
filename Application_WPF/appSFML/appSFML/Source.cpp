#include <iostream>
#include <vector>
#include "Header.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1450, 775), "");
    std::vector<tslButton> buttonsWindow;
    std::vector<tslTextBox> textBoxesWindow;
    bool keyFlag = 1;
    bool flag45 = 1;
    int longPress = 0;
    char currentLetter = ' ';
    
    tslButton b1(1200, 10, 150, 60, sf::Color::Black, window);
    b1.setButtonText("Test");
    b1.setFontSize(20);
    buttonsWindow.push_back(b1);


    tslTextBox t1(10, 50, 1000, 20, window);
    t1.setTextBoxText("");
    t1.setFontSize(14);
    t1.setMaxLetters(124);
    textBoxesWindow.push_back(t1);

    tslTextBox t2(10, 230, 100, 20, window);
    t2.setTextBoxText("");
    t2.setFontSize(14);
    textBoxesWindow.push_back(t2);

    tslTextBox t3(10, 260, 50, 20, window);
    t3.setTextBoxText("");
    t3.setFontSize(14);
    textBoxesWindow.push_back(t3);

    renderMainWindow(window, buttonsWindow, textBoxesWindow);
    

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
            if (buttonsWindow[0].isClicked()) {
     
                std::cout << 1 << std::endl;
            }
            else if (textBoxesWindow[0].isClicked()) {
                renderMainWindow(window, buttonsWindow, textBoxesWindow);
                std::cout << 2 << std::endl;
            }
            else if (textBoxesWindow[1].isClicked()) {
                renderMainWindow(window, buttonsWindow, textBoxesWindow);
                std::cout << 2 << std::endl;
            }
            else if (textBoxesWindow[2].isClicked()) {
                renderMainWindow(window, buttonsWindow, textBoxesWindow);
                std::cout << 2 << std::endl;
            }


            if (!textBoxesWindow[0].isClicked()) {
                renderMainWindow(window, buttonsWindow, textBoxesWindow);
                std::cout << "!2" << std::endl;
            }
            if (!textBoxesWindow[1].isClicked()) {
                renderMainWindow(window, buttonsWindow, textBoxesWindow);
                std::cout << 2 << std::endl;
            }
            if (!textBoxesWindow[2].isClicked()) {
                renderMainWindow(window, buttonsWindow, textBoxesWindow);
                std::cout << 2 << std::endl;
            }
            sf::sleep(delayTime);
        }

        if (event.type == sf::Event::KeyReleased) {
            keyFlag = 1;
            longPress = 0;
        }

        if (event.type == sf::Event::TextEntered) {
            if (longPress < 100000) {
                ++longPress;
            }
        }

        if (event.type == sf::Event::TextEntered && currentLetter != event.key.code) {
            keyFlag = 1;
        }

        if (event.type == sf::Event::TextEntered) {
            if (keyFlag || longPress == 100000) {
                keyLogger(window, buttonsWindow, textBoxesWindow, event.key.code);
                currentLetter = event.key.code;
                keyFlag = 0;
            }
        }

    }

    return 0;
}