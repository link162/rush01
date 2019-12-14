#ifndef IMONITORDISPLAY
#define IMONITORDISPLAY

#include "header.hpp"

class IMonitorDisplay
{
public:
    virtual ~IMonitorDisplay(void){};

    virtual void init(void) = 0;
    virtual void update(void) = 0;
};

#endif
