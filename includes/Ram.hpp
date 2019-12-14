#ifndef RAM
#define RAM

#include "header.hpp"

class Ram : public IMonitorModule
{
	private:
	std::string hostname;
	public:
	Ram();
	~Ram();
	Ram(const Ram &old);
	Ram &operator = (const Ram &old);
	void update();
};

#endif
