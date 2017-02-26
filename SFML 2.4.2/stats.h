#pragma once

struct stats
{
	float strengh;
	float pace;
	float hp;
	stats():strengh(0), pace(0), hp(0){}
	stats(float strengh, float pace, float hp): strengh(strengh), pace(pace), hp(hp){}
};