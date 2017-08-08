
#include "GameLogic.h"

#include "Ship.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Common.h"


int main(int argc, char *argv[]) {
	int i_input;
	GameLogic newGame;
	do {
		newGame.drawFrame();
		i_input = _getch();		
		switch (i_input) {
		case PAUSE:
			newGame.pauseGame();
			break;
		default:
			newGame.doAction(i_input);
			
		}
	} while (i_input != ESCAPE);
	
	return 0;
}



