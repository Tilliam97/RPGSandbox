#include "Ranger.h"

Ranger::Ranger(std::string Rangername)
{
	name = Rangername;
	lvl = new int(1);
	HP = new float(150.0f);
	def = new double(90.00);
	attk = new double(55.00);
	spd = new double(110.00);
	stam = new double(65.00);
	mana = new double(5.00);
	lockOn = new int(1);
}

Ranger::~Ranger()
{
	delete lvl;
	delete HP;
	delete def;
	delete attk;
	delete spd;
	delete stam;
	delete mana;
	delete lockOn;
}

std::string Ranger::getName()
{
	return name;
}

int Ranger::getLevel()
{
	return *lvl;
}

float Ranger::getHealth()
{
	return *HP;
}

double Ranger::getAttack()
{
	return *attk;
}

double Ranger::getSpeed()
{
	return *spd;
}

double Ranger::getStamina()
{
	return *stam;
}

double Ranger::getMana()
{
	return *mana;
}

int Ranger::getlockOn()
{
	return *lockOn;
}

void Ranger::levelUp(int level)
{
	*lvl += level;

	if (*lvl <= 55)
	{
		*HP += (*lvl * 10);
		*attk += (*lvl * 5);
		*spd += (*lvl * 4);
		*stam += (*lvl * 4);
		*mana = (*lvl * 2);

		if (*lvl > 1 && *lvl <= 50)
		{
			if (*lvl % 10 == 0)
			{
				*lockOn += 1; //every 5 levels add a bar of rage and cap at 5 bars at 25  **may adjust to 50**
			}
			else if (*lvl > 9)
			{
				int remainder = 0;

				if (*lvl % 10 != 0 && *lvl <= 50)
				{
					remainder = *lvl % 10;

					int stored = *lvl - remainder;

					if (stored % 10 == 0)
					{
						*lockOn = (stored / 10) + 1;
					}
				}
			}
		}
		else if (*lvl >= 50)
		{
			*lockOn = 5;
		}
	}

	typeWriter(name + " Leveled Up!");
	typeWriter("Level = " + std::to_string(*lvl));
	typeWriter("Health = " + truncateFloat(*HP));
	typeWriter("Attack = " + truncateDouble(*attk));
	typeWriter("Speed = " + truncateDouble(*spd));
	typeWriter("Stamina = " + truncateDouble(*stam));
	typeWriter("Mana = " + truncateDouble(*mana));
	typeWriter("Lock On = " + std::to_string(*lockOn) + "\n");
}