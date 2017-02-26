#pragma once
#include "item.h"
#include <iostream>


class Inventory
{
	int size;
	int index;
	Item* tab;


public:
	Inventory();
	~Inventory();
	void add(Item);
	Item getItem(int);
	int getSize();
	int getIndex();

};