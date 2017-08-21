#ifndef COMMON_H
#define COMMON_H

#include <iostream> 
#include <stdlib.h>
#include  <conio.h>
#include <stdio.h>

const int SIZE_BATTLEFIELD = 10;

const int SIZE_4TYPE_SHIP = 4;
const int SIZE_3TYPE_SHIP = 3;
const int SIZE_2TYPE_SHIP = 2;
const int SIZE_1TYPE_SHIP = 1;

const int COUNT_4TYPE_SHIP = 1;
const int COUNT_3TYPE_SHIP = 2;
const int COUNT_2TYPE_SHIP = 3;
const int COUNT_1TYPE_SHIP = 4;

const int HORIZONTAL = 0;
const int VERTICAL = 1;

const int ENTER = 13;
const int SPACE = 32;
const int ESCAPE = 27;
const int KEY_W = 119;
const int KEY_S = 115;
const int KEY_A = 97;
const int KEY_D = 100;
const int PAUSE = 112;

const int EMPTY = 0;
const int ALIVE = 1;
const int INJUR = 3;
const int KILL = 4;
const int MISS = 5;
const int NOT_AVAILABLE = 6;


using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point() {
		this->x = 0;
		this->y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
};
#endif 
