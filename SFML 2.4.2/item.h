#pragma once
#include "stats.h"
#include <string>
#include <SFML/Graphics.hpp>

using sf::Texture;
using sf::Sprite;
using std::string;

class Item
{
	stats i_stats;
	string name;
	string file;

	Texture i_texture;
	Sprite i_sprite;

public:
	Item();

	/*konstruktor argumentowy
	`1. sila, 2. tempo. 3. hp, 4 nazwa, 5. sciezka do pliku*/
	Item(float, float, float, string, string);
	~Item();

	void setItemPosition(sf::Vector2f);


	//GETTERY
	Sprite getSprite();

};