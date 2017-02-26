#include "inventory.h"

Inventory::Inventory() :index(0), size(6)
{
	tab = new Item[size];
}

Inventory::~Inventory(){}

void Inventory::add(Item tmp)
{
	if (index < size)
	{
		tab[index] = tmp;
		index++;
	}
	else
		std::cout << "INVENTORY FULL" << std::endl;
}

Item Inventory::getItem(int index)
{
	return tab[index];
}

int Inventory::getSize()
{
	return size;
}

int Inventory::getIndex()
{
	return index;
}
