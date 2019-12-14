#ifndef CPU
#define CPU

#include "header.hpp"

class Cpu : public IMonitorModule
{
	private:
	std::string hostname;
	public:
	Cpu();
	~Cpu();
	Cpu(const Cpu &old);
	Cpu &operator = (const Cpu &old);
	void update();
};

#endif
