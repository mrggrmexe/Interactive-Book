#include "Header.h"


void renderMainWindow(sf::RenderWindow&        window,
	                  std::vector<tslButton>&  buttonsWindow,
	                  std::vector<tslTextBox>& textBoxesWindow) {

	window.clear(sf::Color::White);

	for (int i = 0; i < buttonsWindow.size(); ++i) {
		buttonsWindow[i].render();
	}

	for (int i = 0; i < textBoxesWindow.size(); ++i) {
		textBoxesWindow[i].render();
	}

	window.display();

}

void keyLogger(sf::RenderWindow&        window,
	           std::vector<tslButton>&  buttonsWindow,
	           std::vector<tslTextBox>& textBoxesWindow, 
	           char                     newSymbol) {

	for (int i = 0; i < textBoxesWindow.size(); ++i) {
		if (textBoxesWindow[i].getFocus()) {
			textBoxesWindow[i].changeText(newSymbol);
			renderMainWindow(window, buttonsWindow, textBoxesWindow);
		}
	}

}