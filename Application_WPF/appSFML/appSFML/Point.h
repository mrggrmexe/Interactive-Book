#pragma once

class Point {
public:
	int x, y;
	Point(int _x, int _y)
		: x(_x), y(_y) {}
};

Point mousePos(sf::RenderWindow& window) {
	Point mouseCurrentPosition(sf::Mouse::getPosition(window).x,
		sf::Mouse::getPosition(window).y);

	return mouseCurrentPosition;
}