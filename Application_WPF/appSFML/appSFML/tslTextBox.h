#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Point.h"


class tslTextBox {
public:

	tslTextBox(int _x, int _y, int _width, int _height, sf::RenderWindow& _window);
	void render();

	void setSize(int _width, int _height);
	void setPosition(int _x, int _y);
	void setTextBoxText(std::string _textBoxText);
	void setFontSize(int _fontSize);
	void setColorText(sf::Color _colorText);
	void setMaxLetters(int _maxLetters);

	bool getFocus();

	bool isClicked();

	void changeText(char _newSymbol);


private:

	// ��������� ��������������
	Point position;
	int height, width;

	// ��������� ������
	sf::Font font;
	int fontSize;
	std::string textBoxText;
	sf::Color colorText = sf::Color::Black;

	// �����������
	bool focused = 0;
	int lineSize = 1;

	// �����������
	int maxLetters = 0;

	sf::RenderWindow& window;

};