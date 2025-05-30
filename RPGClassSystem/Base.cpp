#include "Base.h"

Base::Base()
{
}

Base::~Base()
{

}

void Base::levelUp(int level)
{
}

void Base::typeWriter(const std::string& text, int delay)
{
	for (char c : text)
	{
		std::cout << c;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
		std::cout << std::endl;

}


