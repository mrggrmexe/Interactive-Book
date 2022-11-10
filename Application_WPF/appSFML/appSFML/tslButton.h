#include <SFML/Graphics.hpp>
#include <string>
#include "Point.h"
#pragma once


class tslButton {
public:

	tslButton(int _x, int _y, int _width, int _height, sf::Color _color, sf::RenderWindow& _window);
	void render();

	void setSize(int _width, int _height);
	void setPosition(int _x, int _y);
	void setButtonText(std::string _buttonString);
	void setFontSize(int _fontSize);
	void setColorText(sf::Color _colorText);

	bool isClicked(Point clickPosition);

private:

	// Параметры прямоугольника
	Point position;
	int height, width;
	sf::Color color;

	// Параметры текста
	sf::Font font;
	int fontSize;
	std::string buttonText;
	sf::Color colorText = sf::Color::White;

	sf::RenderWindow& window;
};

