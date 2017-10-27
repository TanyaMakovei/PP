#pragma once
#include "Car.h"
#include "Field.h"
#include "GameLogic.h"
#include <time.h>
#include <iostream> 
#include <cstdlib>
#include <cstdio>
#include <concrt.h>


using namespace std;

const int TREE = 1;
const int EMPTY = 0;
const int CAR = 2;

const int FIELD_WIDTH = 20;
const int FIELD_LENGHT = 40;

const int START_X = 39;
const int START_Y = 10;

const int MAX_COUNT_OF_TREES = 8;

const int MIN_SPEED = 1;
const int MAX_SPEED = 9;

const int SYMBOL_CAR = 0xb2;
const int SYMBOL_FIELD = 0xb0;
const int SYMBOL_TREE = 0xb1;
const int SYMBOL_HIT = 0xcd;



