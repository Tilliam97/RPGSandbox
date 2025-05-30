#include "Thief.h"

Thief::Thief(std::string Thiefname)
{
	name = Thiefname;
	lvl = new int(1);
	HP = new float(150.0f);
	def = new double(90.00);
	attk = new double(55.00);
	spd = new double(110.00);
	stam = new double(65.00);
	mana = new double(5.00);
	cloak = new int(1);
}

Thief::~Thief()
{
	delete lvl;
	delete HP;
	delete def;
	delete attk;
	delete spd;
	delete stam;
	delete mana;
	delete cloak;
}

std::string Thief::getName()
{
	return name;
}

int Thief::getLevel()
{
	return *lvl;
}

float Thief::getHealth()
{
	return *HP;
}

double Thief::getAttack()
{
	return *attk;
}

double Thief::getSpeed()
{
	return *spd;
}

double Thief::getStamina()
{
	return *stam;
}

double Thief::getMana()
{
	return *mana;
}

void Thief::levelUp(int level)
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
				*cloak += 1; //every 5 levels add a bar of cloak and cap at 5 bars at 25  **may adjust to 50**
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
						*cloak = (stored / 10) + 1;
					}
				}
			}
		}
		else if (*lvl >= 50)
		{
			*cloak = 5;
		}
	}

	typeWriter(name + " Leveled Up!");
	typeWriter("Level = " + std::to_string(*lvl));
	typeWriter("Health = " + truncateFloat(*HP));
	typeWriter("Attack = " + truncateDouble(*attk));
	typeWriter("Speed = " + truncateDouble(*spd));
	typeWriter("Stamina = " + truncateDouble(*stam));
	typeWriter("Mana = " + truncateDouble(*mana));
	typeWriter("Cloaking = " + std::to_string(*cloak) + "\n");
}
