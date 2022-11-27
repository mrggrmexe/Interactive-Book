#include "tslTextBox.h"
#include <iostream>
#include <cmath>


//////////////////////////////////////////////////////////////////////
/// ÊÎÍÑÒÐÓÊÒÎÐ

tslTextBox::tslTextBox(int _x, int _y, int _width, int _height, sf::RenderWindow& _window)
	: position(_x, _y), width(_width), height(_height), window(_window) {
}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/// ÎÒÐÈÑÎÂÊÀ ÁËÎÊÀ

void tslTextBox::render() {

	// îòðèñîâêà ïðÿìîóãîëüíèêà
	sf::RectangleShape textBoxRectangle;
	textBoxRectangle.setPosition(position.x, position.y);
	textBoxRectangle.setOutlineColor(sf::Color::Black);
	textBoxRectangle.setOutlineThickness(lineSize);
	textBoxRectangle.setSize(sf::Vector2f(width, height));
	window.draw(textBoxRectangle);

	// îòðèñîâêà òåêñòà
	font.loadFromFile("RobotoText.ttf");
	sf::Text text("", font, fontSize);
	if (textBoxText.size() > maxLetters) {
		text.setString(textBoxText.substr(textBoxText.size() - maxLetters));
	}
	else {
		text.setString(textBoxText.substr(0));
	}
	// ïî óìîë÷àíèþ ïî öåíòðó (0.6 - îòíîøåíèå pt è px äëÿ øðèôòà Roboto)
	text.setPosition(position.x + 3, position.y + 1);
	text.setFillColor(colorText);
	window.draw(text);

}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/// ÑÅÒÒÅÐÛ

void tslTextBox::setSize(int _height, int _width) {

	height = _height;
	width = _width;
}

void tslTextBox::setPosition(int _x, int _y) {

	position.x = _x;
	position.y = _y;
}

void tslTextBox::setTextBoxText(std::string _textBoxText) {

	textBoxText = _textBoxText;
}

void tslTextBox::setFontSize(int _fontSize) {

	fontSize = _fontSize;
}

void tslTextBox::setMaxLetters(int _maxLetters) {

	maxLetters = _maxLetters;
}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/// ÃÅÒÒÅÐÛ

bool tslTextBox::getFocus() {

	return focused;
}

/////////////////////////////////////////////////////////////////////


bool tslTextBox::isClicked() {

	Point clickPosition = mousePosition(window);

	if (clickPosition.x >= position.x && clickPosition.x <= position.x + width &&
		clickPosition.y >= position.y && clickPosition.y <= position.y + height) {

		focused = 1;
		lineSize = 2;

		return 1;
	}

	focused = 0;
	lineSize = 1;

	return 0;
}


void tslTextBox::changeText(char _newSymbol) {

	if (textBoxText.size() > 0 && _newSymbol == 8) {
		textBoxText.pop_back();
	}
	else if (_newSymbol != 8) {
		textBoxText += _newSymbol;
	}

	std::cout << textBoxText.size() << std::endl;

}