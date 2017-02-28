#include "inventory.h"

Inventory::Inventory() :index(0), size(6), position(105,110)
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
		std::cout << "ITEM ADDED" << std::endl;
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


void Inventory::view(sf::RenderWindow & window)
{
	for (int i = 0; i < index; i++)
	{

		tab[i].setItemPosition(position + Vector2f(i * 32,0));
		window.draw(tab[i].getSprite());
		
	}
			
}


