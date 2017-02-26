#include "item.h"

Item::Item() :i_stats(), name("Unknown Item"), file("items/ladder.png")
{
	i_texture.loadFromFile(file);
	i_sprite.setTexture(i_texture);
	i_sprite.setPosition(50, 50);
}

Item::Item(float strengh, float pace, float hp, string name, string file): i_stats(strengh, pace, hp), name(name), file(file)
{
	//cialo
}

Item::~Item(){}

Sprite Item::getSprite()
{
	return i_sprite;
}
