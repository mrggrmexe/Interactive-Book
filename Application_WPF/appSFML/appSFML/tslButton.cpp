#include "tslButton.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////
/// ÊÎÍÑÒÐÓÊÒÎÐ

tslButton::tslButton(int _x, int _y, int _width, int _height, sf::Color _color, sf::RenderWindow& _window)
	: position(_x, _y), width(_width), height(_height), color(_color), window(_window) {
}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/// ÎÒÐÈÑÎÂÊÀ ÊÍÎÏÊÈ

void tslButton::render() {

	// îòðèñîâêà ïðÿìîóãîëüíèêà
	sf::RectangleShape buttonRectangle;
	buttonRectangle.setPosition(position.x, position.y);
	buttonRectangle.setFillColor(color);
	buttonRectangle.setSize(sf::Vector2f(width, height));
	window.draw(buttonRectangle);

	// îòðèñîâêà òåêñòà
	font.loadFromFile("RobotoText.ttf");
	sf::Text text("", font, fontSize);
	text.setString(buttonText);
	// ïî óìîë÷àíèþ ïî öåíòðó (0.6 - îòíîøåíèå pt è px äëÿ øðèôòà Roboto)
	text.setPosition(position.x + (width - fontSize * buttonText.size() * 0.6) / 2, position.y + height / 2 - fontSize * 0.6);
	text.setFillColor(colorText);
	window.draw(text);

}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/// ÑÅÒÒÅÐÛ

void tslButton::setSize(int _height, int _width) {
	height = _height;
	width = _width;
}

void tslButton::setPosition(int _x, int _y) {
	position.x = _x;
	position.y = _y;
}

void tslButton::setButtonText(std::string _buttonText) {
	buttonText = _buttonText;
}

void tslButton::setFontSize(int _fontSize) {
	fontSize = _fontSize;
}

/////////////////////////////////////////////////////////////////////


bool tslButton::isClicked() {
	Point clickPosition = mousePosition(window);
	
	if (clickPosition.x >= position.x && clickPosition.x <= position.x + width &&
		clickPosition.y >= position.y && clickPosition.y <= position.y + height) {

		return 1;
	}
	return 0;
}