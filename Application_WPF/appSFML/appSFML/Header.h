#pragma once

#include "tslButton.h"
#include "tslTextBox.h"
#include "Point.h"





void renderMainWindow(sf::RenderWindow&        window, 
	                  std::vector<tslButton>&  buttonsWindow,
	                  std::vector<tslTextBox>& textBoxesWindow,
					  std::string& problem);

void keyLogger(sf::RenderWindow&        window, 
	           std::vector<tslButton>&  buttonsWindow,
	           std::vector<tslTextBox>& textBoxesWindow, 
	           char                     newSymbol,
	           std::string problem);