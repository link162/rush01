#ifndef NETWORK
#define NETWORK

#include "header.hpp"

class Network : public IMonitorModule
{
	private:
	std::string pkt_in;
	public:
	Network();
	~Network();
	Network(const Network &old);
	Network &operator = (const Network &old);
	void update();
};

#endif
