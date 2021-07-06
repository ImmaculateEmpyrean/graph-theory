#include<iostream>
#include<random>

int random(int min, int max)
{
	return std::rand() % (max - min + 1) + min;
}