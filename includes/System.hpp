#ifndef SYSTEM
#define SYSTEM

#include "header.hpp"

class System : public IMonitorModule
{
	private:
	std::string hostname;
	public:
	System();
	~System();
	System(const System &old);
	System &operator = (const System &old);
	void update();
};

#endif
