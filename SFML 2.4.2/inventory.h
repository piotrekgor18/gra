#pragma once
#include "item.h"
#include <iostream>

using sf::Vector2f;

class Inventory
{
	int size;
	int index;
	Vector2f position;
	Item* tab;



public:
	Inventory();
	~Inventory();
	void add(Item);
	Item getItem(int);
	int getSize();
	int getIndex();

	void view(sf::RenderWindow&);

};