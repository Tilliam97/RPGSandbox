#pragma once
#include "Base.h"
class Warrior : public Base
{
public:
	Warrior(std::string Brutename = "Guts");
	~Warrior();

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
	double* def, * attk, * spd, * stam, * mana;
	int* negate;
};

