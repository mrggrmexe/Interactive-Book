#include "tslButton.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////
/// �����������

tslButton::tslButton(int _x, int _y, int _width, int _height, sf::Color _color, sf::RenderWindow& _window)
	: position(_x, _y), width(_width), height(_height), color(_color), window(_window) {
}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/// ��������� ������

void tslButton::render() {

	// ��������� ��������������
	sf::RectangleShape buttonRectangle;
	buttonRectangle.setPosition(position.x, position.y);
	buttonRectangle.setFillColor(color);
	buttonRectangle.setSize(sf::Vector2f(width, height));
	window.draw(buttonRectangle);

	// ��������� ������
	font.loadFromFile("RobotoText.ttf");
	sf::Text text("", font, fontSize);
	text.setString(buttonText);
	// �� ��������� �� ������ (0.6 - ��������� pt � px ��� ������ Roboto)
	text.setPosition(position.x + (width - fontSize * buttonText.size() * 0.6) / 2, position.y + height / 2 - fontSize * 0.6);
	std::cout << height;
	text.setFillColor(colorText);
	window.draw(text);

}

/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/// �������

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


bool tslButton::isClicked(Point clickPosition) {
	if (clickPosition.x >= position.x && clickPosition.x <= position.x + height &&
		clickPosition.y >= position.y && clickPosition.y <= position.y + width) {

		return 1;
	}
	return 0;
}