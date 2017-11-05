#ifndef TREE_H
#define TREE_H

#include "Helper.h"

class Tree
{
public:
	Tree(int type);
	~Tree();

	int getSizeX() const;
	int getSizeY() const;


private:
	int sizeX_,
		sizeY_;

};

#endif TREE_H