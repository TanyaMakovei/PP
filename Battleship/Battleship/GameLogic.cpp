#include "GameLogic.h"
#include "Windows.h"
#include "conio.h"


char GameLogic::Buf[BUF_HEIGHT][BUF_WIDTH];

GameLogic::GameLogic()
{
	player1.setStatus(1);
	player2.setStatus(0);
	int i, j;

	//"└──────────────────────┘"
	for ( i=0;i<BUF_HEIGHT;i++)
	{
		for ( j=0; j<BUF_WIDTH_F;j++) {
			Buf[i][j] = 0xb0;
		}
	}
	for (i = 0;i < BUF_HEIGHT;i++)
	{
		for (j = 0; j < BUF_SHIFT;j++) {
			Buf[i][j+ BUF_WIDTH_F] = 0x2504;
		}
	}
	for (i = 0;i < BUF_HEIGHT;i++)
	{
		for (j = 0; j < BUF_WIDTH_F;j++) {
			Buf[i][j + BUF_WIDTH_F+BUF_SHIFT] = 0xb0;
		}
	}

}

void writeString(int row, LPCSTR arg) {
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 5, row + 5 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!WriteConsoleOutputCharacterA(hStdOut, arg,
		strlen(arg), homeCoords, &count))
		return;
}
int i = 0;
GameLogic::~GameLogic()
{
}

void GameLogic::pauseGame()
{
}

void GameLogic::printStatistic()
{
}

void GameLogic::doAction(int i_input)
{
	if (player1.getMode() == ShipArrangement) {
		
		switch (i_input) {
		case 'w':
			cursor.setPosition(0, -1);//up
			break;
		case 's':
			cursor.setPosition(0, 1);//down
			break;
		case 'a':
			cursor.setPosition(1, -1);//left
			break;
		case 'd':
			cursor.setPosition(1, 1);//right
			break;
		case 13:
			player1.setShip(cursor.position.getX(), cursor.position.getY());//enter
			break;
		case 32:
			player1.changeDirection();			//space
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

void GameLogic::checkHit(int x, int y, Battlefield playerA, Battlefield playerB)
{
	if (playerB.getMyPoint(x, y) == 0) {
		playerA.setEnemyPoint(x, y, 5);
		//промах
	}
	else if (playerB.getMyPoint(x, y) == 1) {

	}
}



void GameLogic::drawFrame()
{
	Battlefield player;
	//clear_terminal();//system("cls");
	if (player1.getStatus() == 1) {
		player = player1;
	}
	else if (player2.getStatus() == 1) {
		player = player2;
	}
	
	for (int x = 0;x < BUF_HEIGHT;x++)
	{
		for (int y = 0; y< BUF_WIDTH_F;y=y+2) {
			Buf[x][y]=player.drawFrame(x, y/2);
			Buf[x][y+1] = player.drawFrame(x, y / 2);
		}
	}
// 	if (player.getDirection() == 0) {
// 		if (countShip == 0) {
// 			for (int l = 0; l < 8; l++) {
// 				Buf[cursor.position.getX()][cursor.position.getY()+l] = 0xdb;
// 			}
// 		}
// 		else if (countShip > 0 && countShip <= 2) {
// 			for (int l = 0; l < 6; l++) {
// 				Buf[cursor.position.getX()][cursor.position.getY() + l] = 0xdb;
// 			}
// 
// 		}
// 		else if (countShip > 2 && countShip <= 5) {
// 			for (int l = 0; l < 4; l++) {
// 				Buf[cursor.position.getX()][cursor.position.getY() + l] = 0xdb;
// 			}
// 		}
// 		else if (countShip > 5 && countShip <= 9) {
// 			Buf[cursor.position.getX() ][cursor.position.getY()] = 0xdb;
// 			Buf[cursor.position.getX() ][cursor.position.getY() + 1] = 0xdb;
// 
// 		}
// 	}else if (player.getDirection() == 1)
// 	{
// 		if (countShip == 0) {
// 			for (int l=0; l < 4; l++) {
// 				Buf[cursor.position.getX()+l][cursor.position.getY()] = 0xdb;
// 				Buf[cursor.position.getX()+l][cursor.position.getY() + 1] = 0xdb;
// 			}
// 		}
// 		else if (countShip > 0 && countShip <= 2) {
// 			for (int l = 0; l < 3; l++) {
// 				Buf[cursor.position.getX() + l][cursor.position.getY()] = 0xdb;
// 				Buf[cursor.position.getX() + l][cursor.position.getY() + 1] = 0xdb;
// 			}
// 
// 		}
// 		else if (countShip > 2 && countShip <= 5) {
// 			for (int l = 0; l < 2; l++) {
// 				Buf[cursor.position.getX() + l][cursor.position.getY()] = 0xdb;
// 				Buf[cursor.position.getX() + l][cursor.position.getY() + 1] = 0xdb;
// 			}
// 		}
// 		else if (countShip > 5 && countShip <= 9) {
// 				Buf[cursor.position.getX() ][cursor.position.getY()] = 0xdb;
// 				Buf[cursor.position.getX() ][cursor.position.getY() + 1] = 0xdb;
// 			
// 		}
// 
// 	}
	   
		for (int i = 0;i < BUF_HEIGHT;i++)
		{
			writeString(i, Buf[i]);//	cout << Buf[i];
		}
	
}
