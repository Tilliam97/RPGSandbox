#pragma once
#include "Base.h"

class Brute : public Base
{

public:
	Brute(std::string Brutename = "Broly");
	~Brute();

#pragma region Getters

	std::string getName();
	int getLevel();
	float getHealth();
	double getAttack();
	double getSpeed();
	double getStamina();
	double getMana();

#pragma endregion

	void levelUp(int level = 1) override;

private:
	std::string name;
	int* lvl;
	float* HP;
	double* def, *attk, *spd, *stam, *mana;
	int* rage;

};

