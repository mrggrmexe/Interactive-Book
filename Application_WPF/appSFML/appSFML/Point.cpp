#include "Header.h"

Point mousePosition(sf::RenderWindow& window) {
	Point mouseCurrentPosition(sf::Mouse::getPosition(window).x,
		sf::Mouse::getPosition(window).y);

	return mouseCurrentPosition;
}