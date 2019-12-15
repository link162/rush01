#ifndef IMONITORDISPLAY
#define IMONITORDISPLAY

#include "header.hpp"

class Monitor;
class IMonitorDisplay
{
public:
    virtual ~IMonitorDisplay(void){};

    virtual void init(void) = 0;
    virtual void update(Monitor const *m) = 0;
	virtual void display(Monitor const *m) = 0;
};

#endif
