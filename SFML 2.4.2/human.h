#pragma once
#include "stats.h"
#include <string>

using std::string;

enum direction { up, down, right, left };

class Human
{
protected:
	//statystyki
	stats s_stats;

	//imie
	string name;

	//nazwa pliku z wygladem
	string file;

	//poruszanie sie
	bool walk;
	direction dir;

public:
	Human();
	Human(float, float, float, string, string, bool, direction);
	~Human();

};