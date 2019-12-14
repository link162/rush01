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
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Monitor.hpp"
#include "Time.hpp"
#include "Hostname.hpp"
#include "Network.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"
#include "System.hpp"

#define STD_BUFF 100
#define PRINT(s) std::cout << (s) << std::endl

#endif
