#pragma once
#include "Utils.h"



class Base // Abstract base class 
{
private:
	std::string name = "default";
	float* HP = nullptr;
	double *def = nullptr, *attk = def , *spd = def, *stam = def, *mana = def; //initialized and set to same value 0.00
	int* lvl = 0;

public:
	Base();
	~Base();

#pragma region ABC Fields
	virtual std::string getName() = 0;
	virtual int getLevel() = 0;
	virtual float getHealth() = 0;
	virtual double getAttack() = 0;
	virtual double getSpeed() = 0;
	virtual double getStamina() = 0;
	virtual double getMana() = 0;
	virtual void levelUp(int level) = 0;
#pragma endregion 

	virtual void typeWriter(const std::string& text, int delay = 25);

};

