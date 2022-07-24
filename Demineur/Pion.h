#pragma once
#include <stdlib.h>
#include "Pion.cpp"

class Pion
{
private:
	bool reveler, mine;
	int nbMine;
public:
	Pion();
	~Pion();
	bool estRevelée() const;
};