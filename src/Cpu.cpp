#include "header.hpp"

Cpu::Cpu() { std::cout << "create Cpu\n";}
Cpu::~Cpu() { std::cout << "delete Cpu\n";}
Cpu::Cpu(const Cpu &old)
{
	*this = old;
}
Cpu &Cpu::operator = (const Cpu &old)
{
	*this = old;
	return *this;
}
void Cpu::update()
{
	//get_curr_time();
}

