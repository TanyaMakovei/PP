#ifndef COMMON_H
#define COMMON_H

#include <iostream> 
#include <stdlib.h>
#include  <conio.h>
#include <stdio.h>
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
