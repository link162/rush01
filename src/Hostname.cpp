#include "header.hpp"

Hostname::Hostname() { std::cout << "create Hostname\n";}
Hostname::~Hostname() { std::cout << "delete Hostname\n";}
Hostname::Hostname(const Hostname &old)
{
	*this = old;
}
Hostname &Hostname::operator = (const Hostname &old)
{
	*this = old;
	return *this;
}
void Hostname::update()
{
	char buff[STD_BUFF];
    size_t buffLen = STD_BUFF;

    sysctlbyname("kern.hostname", &buff, &buffLen, NULL, 0);

    std::string name(buff);
    hostname = name;
}
void Hostname::introduce() const
{
	std::cout << "Host name " << hostname << std::endl;
}
