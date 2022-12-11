#include <iostream>
#include <vector>
#include "Header.h"
#include <random>


int main() {
    sf::RenderWindow window(sf::VideoMode(1450, 775), "");
    std::vector<tslButton> buttonsWindow;
    std::vector<tslTextBox> textBoxesWindow;
    bool keyFlag = 1;
    bool flag45 = 1;
    int longPress = 0;
    char currentLetter = ' ';


    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(1, 6); // distribute results between 1 and 6 inclusive.
    int a, b;
    a = dist(gen);
    b = dist(gen);
    std::string problem;
    problem = std::to_string(a) + " + " + std::to_string(b);
   
    
    tslButton b1(1200, 600, 150, 60, sf::Color::Black, window);
    b1.setButtonText("Test");
    b1.setFontSize(20);
    buttonsWindow.push_back(b1);


    tslTextBox t1(950, 200, 100, 20, window);
    t1.setTextBoxText("");
    t1.setFontSize(14);
    t1.setMaxLetters(12);
    textBoxesWindow.push_back(t1);
   
    renderMainWindow(window, buttonsWindow, textBoxesWindow, problem);



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
     
                if (textBoxesWindow[0].getText() == std::to_string(a + b)) {
                    a = dist(gen);
                    b = dist(gen);
                    problem = std::to_string(a) + " + " + std::to_string(b);
                    textBoxesWindow[0].setTextBoxText("OK");
                }
                else {
                    textBoxesWindow[0].setTextBoxText("WA");
                }
                renderMainWindow(window, buttonsWindow, textBoxesWindow, problem);
            }
            else if (textBoxesWindow[0].isClicked()) {
                textBoxesWindow[0].setTextBoxText("");
                renderMainWindow(window, buttonsWindow, textBoxesWindow, problem);
                std::cout << 2 << std::endl;
            }
            


            if (!textBoxesWindow[0].isClicked()) {
                renderMainWindow(window, buttonsWindow, textBoxesWindow, problem);
                std::cout << "!2" << std::endl;
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
                keyLogger(window, buttonsWindow, textBoxesWindow, event.key.code, problem);
                currentLetter = event.key.code;
                keyFlag = 0;
            }
        }

    }

    return 0;
}