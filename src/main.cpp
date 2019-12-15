#include "header.hpp"


std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
	result = result.substr(0, result.size()-1);
    return result;
}
void print_usage()
{
	std::string us = "Usage: ./ft_gkrillm\n\
					  -l ncurses mode\n\
					  -h help\n\
					  -t time\n\
					  -u hostname\n\
					  -c CPU\n\
					  -n Network\n\
					  -r RAM\n\
					  -o OS info\n";
	std::cout << us ;
	exit(1);
}

int  comp(std::string s1, std::string s2) 
{ 
    if(s1.compare(s2))
		return 1;
	return 0;
      
} 


int main(int argc, char **argv)
{
	int arr[7];
	for (int i = 0; i < 7; i++)
		arr[i] = 0;
	if ((argc == 2 && !comp(argv[1], "-h")) || argc > 7)
		print_usage();
	if (argc == 1 || (argc == 2 && !comp(argv[1], "-l")))
	{
		Monitor grill;
		if (argc == 2)
			grill.ncurses = true;
		grill.run_monitor();
	}
	else
	{
		Monitor grill(0);
		for (int i = 1; i < argc; i++)
		{
			if (!comp(argv[i], "-t") && !arr[0])
			{
				arr[0] = 1;
				grill.add_module(1);
			}
			else if (!comp(argv[i], "-u") && !arr[1])
			{
				arr[1] = 1;
				grill.add_module(2);
			}
			else if (!comp(argv[i], "-c") && !arr[2])
			{
				arr[2] = 1;
				grill.add_module(3);
			}
			else if (!comp(argv[i], "-n") && !arr[3])
			{
				arr[3] = 1;
				grill.add_module(4);
			}
			else if (!comp(argv[i], "-r") && !arr[4])
			{
				arr[4] = 1;
				grill.add_module(5);
			}
			else if (!comp(argv[i], "-o") && !arr[5])
			{
				arr[5] = 1;
				grill.add_module(6);
			}
			else if (!comp(argv[i], "-l") && !arr[6])
			{
				arr[6] = 1;
				grill.add_module(0);
			}
			else
				print_usage();
		}
		grill.run_monitor();
	}
}
