#ifndef HEADER
#define HEADER
#include <functional>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <exception>
#include <map>
#include <queue>
#include <deque>
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>
#include <sstream>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Monitor.hpp"

#define PRINT(s) std::cout << (s) << std::endl
std::string exec(const char *cmd);

#endif
