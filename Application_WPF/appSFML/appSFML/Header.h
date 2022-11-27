#pragma once

#include "tslButton.h"
#include "tslTextBox.h"
#include "Point.h"


void renderMainWindow(sf::RenderWindow&        window, 
	                  std::vector<tslButton>&  buttonsWindow,
	                  std::vector<tslTextBox>& textBoxesWindow);

void keyLogger(sf::RenderWindow&        window, 
	           std::vector<tslButton>&  buttonsWindow,
	           std::vector<tslTextBox>& textBoxesWindow, 
	           char                     newSymbol);