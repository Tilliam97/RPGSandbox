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
		*HP += (*lvl * 5);
		*attk += (*lvl * 5);
		*spd += (*lvl * 6);
		*stam += (*lvl * 4);
		*mana = (*lvl * 3);

		if (*lvl > 1 && *lvl <= 55)
		{
			if (*lvl % 11 == 0)
			{
				*cloak += 1; //every 5 levels add a bar of cloak and cap at 5 bars at 25  **may adjust to 50**
			}
			else if (*lvl > 9)
			{
				int remainder = 0;

				if (*lvl % 11 != 0 && *lvl <= 55)
				{
					remainder = *lvl % 11;

					int stored = *lvl - remainder;

					if (stored % 11 == 0)
					{
						*cloak = (stored / 11) + 1;
					}
				}
			}
		}
		else if (*lvl >= 55)
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
