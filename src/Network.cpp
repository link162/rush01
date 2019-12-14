#include "header.hpp"

Network::Network() { std::cout << "create Network\n";}
Network::~Network() { std::cout << "delete Network\n";}
Network::Network(const Network &old)
{
	*this = old;
}
Network &Network::operator = (const Network &old)
{
	*this = old;
	return *this;
}
void Network::update()
{
	//get_curr_time();
}

