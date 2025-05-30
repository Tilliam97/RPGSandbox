#pragma once
#include "Base.h"
class Ranger :public Base
{
public:
	Ranger(std::string Rangername = "Achilles");
	~Ranger();


#pragma region Getters

	std::string getName();
	int getLevel();
	float getHealth();
	double getAttack();
	double getSpeed();
	double getStamina();
	double getMana();
	int getlockOn();

#pragma endregion

	void levelUp(int level = 1) override;

private:
	std::string name;
	int* lvl;
	int* lockOn;
	float* HP;
	double* def, * attk, * spd, * stam, * mana;

};

