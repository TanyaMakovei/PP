#ifndef HELPER_H
#define HELPER_H

#include <iostream> 
#include <cstdlib>
#include <concrt.h>
#include <conio.h>

using namespace std;

const int TREE = 1;
const int EMPTY = 0;
const int CAR = 2;
const int ENEMY_CAR = 3;

const int ENTER = 13;

const int FIELD_WIDTH = 20;
const int FIELD_LENGHT = 20;

const int START_X = FIELD_LENGHT-1;
const int START_Y = FIELD_WIDTH/2;

const int MAX_COUNT_OF_TREES = 5;

const int MIN_SPEED = 1;
const int MAX_SPEED = 9;
const int SPEED_ENEMY_CAR = 2;

const int COUNT_TYPES_TREES = 2;

const int SYMBOL_CAR = 219;
const int SYMBOL_ENEMY_CAR = 219;//change
const int SYMBOL_FIELD = 0xb0;
const int SYMBOL_TREE = 0xb1;
const int SYMBOL_HIT = 0xcd;

const int SHIFT_FIELD = 3;

const int COEFFICIENT = 50;
const int WAIT_TIME = 500;

const int START_SPEED = 3;
const int START_DISTANCE = -1;
const int START_DISTANCE2 = 0;
const int START_TIME = 0;

const int TREE_RATIO = 2;




#endif HELPER_H