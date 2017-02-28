#include "human.h"

Human::Human(): s_stats(50,5,100), name("Unknown"), file("human/player/character1.png"), walk(0), dir(down)  {}

Human::Human(float strengh, float pace, float hp, string name, string file, bool walk, direction dir): s_stats(strengh, pace, hp), name(name), file(file), walk(walk), dir(dir) {}

Human::~Human(){}
