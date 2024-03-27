#include "Password.hpp"
#include <iostream>
using namespace std;

// static int Help(void);

int	main(int ac, const char* av[])
{
	Password pw;
	(void)ac, (void)av;

	// // help
	// if (string(av[1]) == "-h" || string(av[1]) == "--help")
	// {
	// 	return Help();
	// }
	try
	{
		pw.PrintPassword();
	}
	catch(const char* err)
	{
		cerr << err << endl;
		return 1;
	}
	return 0;
}

// int	Help(void)
// {
// 	cout <<
// 	"pw [option] [Length] [Special Symbols]\n\n" << 
// 	"option:\n" << 
// 	"    -s (--single-password)\n" << 
// 	"        Specify a single password. This option allows you to generate only one password with the specified length.\n" << 
// 	"    -h (--help)\n" << 
// 	"        Display help. This option allows you to view information about command usage and available options.\n";
// 	return 0;
// }
