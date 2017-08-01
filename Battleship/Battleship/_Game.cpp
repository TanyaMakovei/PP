#include "Game.h"



void Game::pauseGame()
{
}

void Game::printStatistic()
{
}





void Game::checkHitPlayer2(int x, int y)
{
	if (player1.getMyPoint(x, y) == 0) {
		player2.setEnemyPoint(x, y, 5);
		//промах
	} else if (player1.getMyPoint(x, y) == 1) {
		
	}
}

void Game::checkHitPlayer1(int x, int y)
{
	if (player2.getMyPoint(x, y) == 0) {
		
		//промах
	}
	else if (player2.getMyPoint(x, y) == 1) {

	}
}

void Game::startGame(int i_input)
{
	if (player1.getMode() == ShipArrangement) {
		
		switch (i_input) {
		case 38:
			cursor.setPosition(1, -1);//up
			break;
		case 40:
			cursor.setPosition(1, 1);//down
			break;
		case 37:
			cursor.setPosition(0, -1);//left
			break;
		case 39:
			cursor.setPosition(0, 1);//right
			break;
		case 13:
			//enter
			break;
		case 32:
			//space
			break;
		default:
			break;
		}
	}
	else if (player1.getMode() == Battle) {
		
		switch (i_input) {
		case 38:
			cursor.setPosition(1, -1);//up
			break;
		case 40:
			cursor.setPosition(1, 1);//down
			break;
		case 37:
			cursor.setPosition(0, -1);//left
			break;
		case 39:
			cursor.setPosition(0, 1);//right
			break;
		case 13:
			//enter
			break;
		default:

			break;
		}
	}
}

