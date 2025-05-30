#include "Wizard.h"


Wizard::Wizard(std::string Wizardname)
{
	name = Wizardname;
	lvl = new int(1);
	HP = new float(110.0f);
	def = new double(55.00);
	attk = new double(70.00);
	spd = new double(40.00);
	stam = new double(40.00);
	mana = new double(15.00);
	spellSlots = new int(1);
}

Wizard::~Wizard()
{
	delete lvl;
	delete HP;
	delete def;
	delete attk;
	delete spd;
	delete stam;
	delete mana;
	delete spellSlots;
}

std::string Wizard::getName()
{
	return name;
}

int Wizard::getLevel()
{
	return *lvl;
}

float Wizard::getHealth()
{
	return *HP;
}

double Wizard::getAttack()
{
	return *attk;
}

double Wizard::getSpeed()
{
	return *spd;
}

double Wizard::getStamina()
{
	return *stam;
}

double Wizard::getMana()
{
	return *mana;
}



void Wizard::levelUp(int level)
{
	*lvl += level;
	if (*lvl <= 55)
	{
		*HP += (*lvl * 5);
		*attk += (*lvl * 3);
		*spd += (*lvl * 2);
		*stam += (*lvl * 2);
		*mana += (*lvl * 5);

		if (*lvl <= 49 && *spellSlots < 7)
		{
			if(*lvl % 7 == 0)
			{ 
				*spellSlots += 1; //every 7 levels (holy #) add a slot for spells and cap at 7 slots at 49 
			}
			else if (*lvl > 6)
			{
				int remainder = 0;

				if (*lvl % 7 != 0 && *lvl <= 49)
				{
					remainder = *lvl % 7;

					int stored = *lvl - remainder; 

					if (stored % 7 == 0)
					{
						*spellSlots = (stored / 7) + 1 ;
					}
				}
			}
		}
		else if (*lvl > 49)
		{
			*spellSlots = 8;
		}
	}

	typeWriter(name + " Leveled Up!");
	typeWriter("Level = " + std::to_string(*lvl));
	typeWriter("Health = " + truncateFloat(*HP));
	typeWriter("Attack = " + truncateDouble(*attk));
	typeWriter("Speed = " + truncateDouble(*spd));
	typeWriter("Stamina = " + truncateDouble(*stam));
	typeWriter("Mana = " + truncateDouble(*mana));
	typeWriter("Spell Slots = " + std::to_string(*spellSlots) + "\n");

}

