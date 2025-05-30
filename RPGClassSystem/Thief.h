#pragma once
#include "Base.h"
class Thief : public Base
{
public:
	Thief(std::string Thiefname = "Charybdis");
	~Thief();

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
	int* cloak;
	float* HP;
	double* def, * attk, * spd, * stam, * mana;

};

