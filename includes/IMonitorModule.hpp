#ifndef IMONITORMODULE
#define IMONITORMODULE

#include "header.hpp"
class IMonitorModule
{
public:
	virtual ~IMonitorModule(void) {};
    virtual void update(void) = 0;
    //virtual const std::string &getName(void) const = 0;

};

#endif
