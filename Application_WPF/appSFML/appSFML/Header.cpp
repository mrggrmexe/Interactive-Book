#include "Header.h"


void renderMainWindow(sf::RenderWindow&        window,
	                  std::vector<tslButton>&  buttonsWindow,
	                  std::vector<tslTextBox>& textBoxesWindow,
	                  std::string& problem) {

	window.clear(sf::Color::White);

	for (int i = 0; i < buttonsWindow.size(); ++i) {
		buttonsWindow[i].render();
	}

	for (int i = 0; i < textBoxesWindow.size(); ++i) {
		textBoxesWindow[i].render();
	}

	// отрисовка текста
	sf::Font font;
	font.loadFromFile("RobotoText.ttf");
	sf::Text text("", font, 30);
	text.setString(problem);
	text.setPosition(10, 10);
	text.setFillColor(sf::Color::Black);
	window.draw(text);

	window.display();

}

void keyLogger(sf::RenderWindow&        window,
	           std::vector<tslButton>&  buttonsWindow,
	           std::vector<tslTextBox>& textBoxesWindow, 
	           char                     newSymbol,
			   std::string problem) {

	for (int i = 0; i < textBoxesWindow.size(); ++i) {
		if (textBoxesWindow[i].getFocus()) {
			textBoxesWindow[i].changeText(newSymbol);
			renderMainWindow(window, buttonsWindow, textBoxesWindow, problem);
		}
	}

}