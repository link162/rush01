#include "header.hpp"

void print_usage()
{
	std::string us = "Usage: ./ft_gkrillm\n\
					  -h help\n\
					  -t time\n\
					  -c CPU\n\
					  -n Network\n\
					  -r RAM\n\
					  -o OS info\n\
					  -u hostname\n";
	std::cout << us ;
}

int  comp(std::string s1, std::string s2) 
{ 
    if(s1.compare(s2))
		return 1;
	return 0;
      
} 


int main(int argc, char **argv)
{
	int arr[6];
	for (int i = 0; i < 6; i++)
		arr[i] = 0;
	if ((argc == 2 && !comp(argv[1], "-h")) || argc > 7)
	{
		print_usage();
	}
	if (argc == 1)
	{
		Monitor grill;
		grill.run_monitor();
	}
	else
	{
		Monitor grill(argc - 1);
		for (int i = 1; i < argc; i++)
			if (!comp(argv[i], "-t") && !arr[0])
			{
				arr[0] = 1;
				grill.add_module(new Time);
			}
			else
				print_usage();
		grill.run_monitor();
	}
}
