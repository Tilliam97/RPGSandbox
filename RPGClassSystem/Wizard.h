#pragma once
#include "Base.h"

class Wizard : public Base
{
public:

#pragma region Wiz Functions 
	
	Wizard(std::string Wizardename = "Merlin");
	~Wizard();

#pragma endregion

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
	int* spellSlots;
};

