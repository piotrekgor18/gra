#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "human.h"

using std::string;
using sf::Sprite;
using sf::Texture;


class Player
	:public Human
{
	//tekstury i sprajty  - trzeba dac je gdzie indziej
	Texture t_image;
	Texture t_talk;

	Sprite s_image;
	Sprite s_talk;

public:

	Player();
	Player(float, float, float, string, string, bool, direction);
	~Player();
	Sprite getImage();
	Sprite getTalk();

	//AKCJA cos tam
	void action();
	void attack();
	void move();



};