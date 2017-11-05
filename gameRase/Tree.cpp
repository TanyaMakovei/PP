#include "Tree.h"



Tree::Tree(int type)
{
	sizeX_ = type;
	sizeY_ = type*TREE_RATIO;
}


Tree::~Tree()
{
}

int Tree::getSizeX() const
{
	return sizeX_;
}

int Tree::getSizeY() const
{
	return sizeY_;
}
