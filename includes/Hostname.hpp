#ifndef HOSTNAME
#define HOSTNAME

#include "header.hpp"

class Hostname : public IMonitorModule
{
	private:
	std::string hostname;
	public:
	Hostname();
	~Hostname();
	Hostname(const Hostname &old);
	Hostname &operator = (const Hostname &old);
	void update();
	void introduce() const;
};

#endif
