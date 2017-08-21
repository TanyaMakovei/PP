#include "GameLogic.h"
#include "Windows.h"
#include "conio.h"


char GameLogic::Buf[BUF_HEIGHT][BUF_WIDTH];

GameLogic::GameLogic()
{
	player1.setStatus(HUMAN);
	player2.setStatus(COMPUTER);
	int i, j;
	isPause = false;
	//"└──────────────────────┘"
	for (i = 0;i < BUF_HEIGHT;i++)
	{
		for (j = 0; j < BUF_WIDTH_F;j++) {
			Buf[i][j] = 0xb0;
		}
	}
	for (i = 0;i < BUF_HEIGHT;i++)
	{
		for (j = 0; j < BUF_SHIFT;j++) {
			Buf[i][j + BUF_WIDTH_F] = 0x2504;
		}
	}
	for (i = 0;i < BUF_HEIGHT;i++)
	{
		for (j = 0; j < BUF_WIDTH_F;j++) {
			Buf[i][j + BUF_WIDTH_F + BUF_SHIFT] = 0xb0;
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
	if (false == isPause)
	{
		//pause
		for (int i = 0;i < BUF_HEIGHT;i++)
		{
			writeString(i, Buf[i]);//	cout << Buf[i];
		}
	}
	else
	{
		drawFrame();
	}
}

void GameLogic::printStatistic()
{
}

void GameLogic::doAction(int i_input)
{
	if (player1.getMode() == ShipArrangement) {
		doArrangmentAction(i_input);
	}
	else if (player1.getMode() == Battle) {

		doBattleAction(i_input);
	}
	
}

void GameLogic::doArrangmentAction(int i_input)
{
	int sizeShip = getTypeShip(player1);
	
	switch (i_input) {
	case KEY_W:
		cursor.setPosition(0, -1, sizeShip, player1.getDirection());//up
		break;
	case KEY_S:
		cursor.setPosition(0, 1, sizeShip, player1.getDirection());//down
		break;
	case KEY_A:
		cursor.setPosition(1, -1, sizeShip, player1.getDirection());//left
		break;
	case KEY_D:
		cursor.setPosition(1, 1, sizeShip, player1.getDirection());//right
		break;
	case ENTER:
		player1.setShip(cursor.position.getX(), cursor.position.getY());
		break;
	case SPACE:
		player1.changeDirection();
		cursor.setPosition(!player1.getDirection(),1-sizeShip,sizeShip, player1.getDirection());
		break;
	default:
		break;
	}
}

void GameLogic::doBattleAction(int i_input)
{
	
	switch (i_input) {
	case KEY_W:
		cursor.setBattlePosition(0, -1);//up
		break;
	case KEY_S:
		cursor.setBattlePosition(0, 1);//down
		break;
	case KEY_A:
		cursor.setBattlePosition(1, -1);//left
		break;
	case KEY_D:
		cursor.setBattlePosition(1, 1);//right
		break;
	case ENTER:

		break;
	default:
		break;
	}
}

void GameLogic::checkHit(int x, int y, Battlefield playerAttac, Battlefield playerDefense)
{
	if (EMPTY == playerDefense.getMyPoint(x, y)) {
		playerAttac.setEnemyPoint(x, y, MISS);
		//промах
	}
	else if (ALIVE == playerDefense.getMyPoint(x, y)) {

	}
}

void GameLogic::drawCursor(Battlefield player)
{
	int direction = player.getDirection();
	int sizeShip = getTypeShip(player);
		drawCursorByType(sizeShip, direction);
	
}

void GameLogic::drawCursorByType(int sizeTypeShip, int direction)
{
	if (HORIZONTAL == direction)
	{
		for (int l = 0; l < sizeTypeShip * 2; l++) {
			Buf[cursor.position.getX()][cursor.position.getY()*2 + l] = 0xdb;

		}
	}
	else if (VERTICAL == direction)
	{
		for (int l = 0; l < sizeTypeShip; l++) {
			Buf[cursor.position.getX() + l][cursor.position.getY()*2] = 0xdb;
			Buf[cursor.position.getX() + l][cursor.position.getY()*2 + 1] = 0xdb;
		}
	}
}

int GameLogic::getTypeShip(Battlefield player)
{
	int countShip = player.getCountShip();
	if (0 > countShip)
	{
		player.setCountShip(0);
	}
	else if (countShip < COUNT_4TYPE_SHIP)
	{
		return SIZE_4TYPE_SHIP;
	}
	else if (countShip <(COUNT_4TYPE_SHIP + COUNT_3TYPE_SHIP))
	{
		return SIZE_3TYPE_SHIP;
	}
	else if (countShip <(COUNT_4TYPE_SHIP + COUNT_3TYPE_SHIP + COUNT_2TYPE_SHIP))
	{
		return SIZE_2TYPE_SHIP;
	}
	else if (countShip < (COUNT_4TYPE_SHIP + COUNT_3TYPE_SHIP + COUNT_2TYPE_SHIP + COUNT_1TYPE_SHIP))
	{
		return SIZE_1TYPE_SHIP;
	}
}



void GameLogic::drawFrame()
{
	Battlefield player;
	
	if (player1.getStatus() == HUMAN) 
	{
		player = player1;
	}
	else if (player2.getStatus() == HUMAN) 
	{
		player = player2;
	}

	for (int x = 0;x < BUF_HEIGHT;x++)
	{
		for (int y = 0; y < BUF_WIDTH_F;y = y + 2) 
		{
			Buf[x][y] = player.drawFrame(x, y / 2);
			Buf[x][y + 1] = player.drawFrame(x, y / 2);
		}
	}
	drawCursor(player);
	for (int i = 0;i < BUF_HEIGHT;i++)
	{
		writeString(i, Buf[i]);//	cout << Buf[i];
	}

}