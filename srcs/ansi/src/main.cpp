#include <iostream>
#include <iomanip>
// #include "ANSI.hpp"
using namespace std;

static void	PrintColor(void);
static void	PrintColorTable(void);
static void PrintGrammar(void);

int	main(int ac, char **av)
{
	// (void)ac, (void)av;
	// ANSI ansi;
	// cout << ansi << "Hello, World!" << ansi.Reset() << endl;
	if (ac == 1)
	{
		PrintColor(); 
	}
	else if (string(av[1]) == "-t" || string(av[1]) == "--table")
	{
		PrintColorTable();
	}
	else if (string(av[1]) == "-g" || string(av[1]) == "--grammar")
	{
		PrintGrammar();
	}
	else
	{
		cout << "Usage: ansi [-t | --table] [-g | --grammar]" << endl;
		return 1;
	}
	return 0;
}

static void	PrintColor(void)
{
	cout 
	<< "Regular Colors\n"
	<< "\033[0;30m\\033[0;30m Black\033[0m\n"
	<< "\033[0;31m\\033[0;31m Red\033[0m\n"
	<< "\033[0;32m\\033[0;32m Green\033[0m\n"
	<< "\033[0;33m\\033[0;33m Yellow\033[0m\n"
	<< "\033[0;34m\\033[0;34m Blue\033[0m\n"
	<< "\033[0;35m\\033[0;35m Purple\033[0m\n"
	<< "\033[0;36m\\033[0;36m Cyan\033[0m\n"
	<< "\033[0;37m\\033[0;37m White\033[0m\n"
	<< "\033[0;39m\\033[0;39m Default\033[0m\n\n"

	<< "Bold\n"
	<< "\033[1;30m\\033[1;30m Black\033[0m\n"
	<< "\033[1;31m\\033[1;31m Red\033[0m\n"
	<< "\033[1;32m\\033[1;32m Green\033[0m\n"
	<< "\033[1;33m\\033[1;33m Yellow\033[0m\n"
	<< "\033[1;34m\\033[1;34m Blue\033[0m\n"
	<< "\033[1;35m\\033[1;35m Purple\033[0m\n"
	<< "\033[1;36m\\033[1;36m Cyan\033[0m\n"
	<< "\033[1;37m\\033[1;37m White\033[0m\n"
	<< "\033[1;39m\\033[1;39m Default\033[0m\n\n"

	<< "Italic\n"
	<< "\033[3;30m\\033[3;30m Black\033[0m\n"
	<< "\033[3;31m\\033[3;31m Red\033[0m\n"
	<< "\033[3;32m\\033[3;32m Green\033[0m\n"
	<< "\033[3;33m\\033[3;33m Yellow\033[0m\n"
	<< "\033[3;34m\\033[3;34m Blue\033[0m\n"
	<< "\033[3;35m\\033[3;35m Purple\033[0m\n"
	<< "\033[3;36m\\033[3;36m Cyan\033[0m\n"
	<< "\033[3;37m\\033[3;37m White\033[0m\n"
	<< "\033[3;39m\\033[3;39m Default\033[0m\n\n"

	<< "Bold Italic\n"
	<< "\033[3;30m\033[1;30m\\033[3;30m\\033[1;30m Black\033[0m\n"
	<< "\033[3;31m\033[1;31m\\033[3;31m\\033[1;31m Red\033[0m\n"
	<< "\033[3;32m\033[1;32m\\033[3;32m\\033[1;32m Green\033[0m\n"
	<< "\033[3;33m\033[1;33m\\033[3;33m\\033[1;33m Yellow\033[0m\n"
	<< "\033[3;34m\033[1;34m\\033[3;34m\\033[1;34m Blue\033[0m\n"
	<< "\033[3;35m\033[1;35m\\033[3;35m\\033[1;35m Purple\033[0m\n"
	<< "\033[3;36m\033[1;36m\\033[3;36m\\033[1;36m Cyan\033[0m\n"
	<< "\033[3;37m\033[1;37m\\033[3;37m\\033[1;37m White\033[0m\n"
	<< "\033[3;39m\033[1;39m\\033[3;39m\\033[1;39m Default\033[0m\n\n"

	<< "Underline\n"
	<< "\033[4;30m\\033[4;30m Black\033[0m\n"
	<< "\033[4;31m\\033[4;31m Red\033[0m\n"
	<< "\033[4;32m\\033[4;32m Green\033[0m\n"
	<< "\033[4;33m\\033[4;33m Yellow\033[0m\n"
	<< "\033[4;34m\\033[4;34m Blue\033[0m\n"
	<< "\033[4;35m\\033[4;35m Purple\033[0m\n"
	<< "\033[4;36m\\033[4;36m Cyan\033[0m\n"
	<< "\033[4;37m\\033[4;37m White\033[0m\n"
	<< "\033[4;39m\\033[4;39m Default\033[0m\n\n"

	<< "Strikethrough\n"
	<< "\033[9;30m\\033[9;30m Black\033[0m\n"
	<< "\033[9;31m\\033[9;31m Red\033[0m\n"
	<< "\033[9;32m\\033[9;32m Green\033[0m\n"
	<< "\033[9;33m\\033[9;33m Yellow\033[0m\n"
	<< "\033[9;34m\\033[9;34m Blue\033[0m\n"
	<< "\033[9;35m\\033[9;35m Purple\033[0m\n"
	<< "\033[9;36m\\033[9;36m Cyan\033[0m\n"
	<< "\033[9;37m\\033[9;37m White\033[0m\n"
	<< "\033[9;39m\\033[9;39m Default\033[0m\n\n"

	<< "Background\n"
	<< "\033[40m\\033[40m Black\033[0m\n"
	<< "\033[41m\\033[41m Red\033[0m\n"
	<< "\033[42m\\033[42m Green\033[0m\n"
	<< "\033[43m\\033[43m Yellow\033[0m\n"
	<< "\033[44m\\033[44m Blue\033[0m\n"
	<< "\033[45m\\033[45m Purple\033[0m\n"
	<< "\033[46m\\033[46m Cyan\033[0m\n"
	<< "\033[47m\\033[47m White\033[0m\n"
	<< "\033[49m\\033[49m Default\033[0m\n\n"

	<< "High Intensity\n"
	<< "\033[0;90m\\033[0;90m Black\033[0m\n"
	<< "\033[0;91m\\033[0;91m Red\033[0m\n"
	<< "\033[0;92m\\033[0;92m Green\033[0m\n"
	<< "\033[0;93m\\033[0;93m Yellow\033[0m\n"
	<< "\033[0;94m\\033[0;94m Blue\033[0m\n"
	<< "\033[0;95m\\033[0;95m Purple\033[0m\n"
	<< "\033[0;96m\\033[0;96m Cyan\033[0m\n"
	<< "\033[0;97m\\033[0;97m White\033[0m\n"
	<< "\033[0;99m\\033[0;99m Default\033[0m\n\n"

	<< "Bold High Intensity\n"
	<< "\033[1;90m\\033[1;90m Black\033[0m\n"
	<< "\033[1;91m\\033[1;91m Red\033[0m\n"
	<< "\033[1;92m\\033[1;92m Green\033[0m\n"
	<< "\033[1;93m\\033[1;93m Yellow\033[0m\n"
	<< "\033[1;94m\\033[1;94m Blue\033[0m\n"
	<< "\033[1;95m\\033[1;95m Purple\033[0m\n"
	<< "\033[1;96m\\033[1;96m Cyan\033[0m\n"
	<< "\033[1;97m\\033[1;97m White\033[0m\n"
	<< "\033[1;99m\\033[1;99m Default\033[0m\n\n"

	<< "High Intensity backgrounds\n"
	<< "\033[0;100m\\033[0;100m Black\033[0m\n"
	<< "\033[0;101m\\033[0;101m Red\033[0m\n"
	<< "\033[0;102m\\033[0;102m Green\033[0m\n"
	<< "\033[0;103m\\033[0;103m Yellow\033[0m\n"
	<< "\033[0;104m\\033[0;104m Blue\033[0m\n"
	<< "\033[0;105m\\033[0;105m Purple\033[0m\n"
	<< "\033[0;106m\\033[0;106m Cyan\033[0m\n"
	<< "\033[0;107m\\033[0;107m White\033[0m\n"
	<< "\033[0;109m\\033[0;109m Default\033[0m\n\n"

	<< "Reset\n"
	<< "\033[0m\\033[0m\n\n"

	<< "\\x1b and \\e are also used instead of \\033\n\n"
	<< "More escape sequences:\n"
	<< "\\033[2J\\033[1;1H Clear screen" << endl;
}

enum eTableLength
{
	TYPE = 20,
	CODE = 22,
	COLOR = 20
};

static void	PrintColorTable(void)
{
	cout << left
	<< setw(TYPE) << "Type" << setw(CODE) << "Code" << setw(COLOR) << "Color" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Regular" << setw(CODE) << "\\033[0;30m" << "\033[0;30m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;31m" << "\033[0;31m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;32m" << "\033[0;32m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;33m" << "\033[0;33m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;34m" << "\033[0;34m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;35m" << "\033[0;35m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;36m" << "\033[0;36m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;37m" << "\033[0;37m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;39m" << "\033[0;39m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Bold" << setw(CODE) << "\\033[1;30m" << "\033[1;30m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;31m" << "\033[1;31m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;32m" << "\033[1;32m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;33m" << "\033[1;33m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;34m" << "\033[1;34m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;35m" << "\033[1;35m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;36m" << "\033[1;36m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;37m" << "\033[1;37m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;39m" << "\033[1;39m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Italic" << setw(CODE) << "\\033[3;30m" << "\033[3;30m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;31m" << "\033[3;31m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;32m" << "\033[3;32m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;33m" << "\033[3;33m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;34m" << "\033[3;34m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;35m" << "\033[3;35m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;36m" << "\033[3;36m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;37m" << "\033[3;37m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;39m" << "\033[3;39m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Bold Italic" << setw(CODE) << "\\033[3;30m\\033[1;30m" << "\033[3;30m\033[1;30m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;31m\\033[1;31m" << "\033[3;31m\033[1;31m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;32m\\033[1;32m" << "\033[3;32m\033[1;32m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;33m\\033[1;33m" << "\033[3;33m\033[1;33m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;34m\\033[1;34m" << "\033[3;34m\033[1;34m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;35m\\033[1;35m" << "\033[3;35m\033[1;35m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;36m\\033[1;36m" << "\033[3;36m\033[1;36m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;37m\\033[1;37m" << "\033[3;37m\033[1;37m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[3;39m\\033[1;39m" << "\033[3;39m\033[1;39m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Underline" << setw(CODE) << "\\033[4;30m" << "\033[4;30m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[4;31m" << "\033[4;31m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[4;32m" << "\033[4;32m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[4;33m" << "\033[4;33m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[4;34m" << "\033[4;34m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[4;35m" << "\033[4;35m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[4;36m" << "\033[4;36m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[4;37m" << "\033[4;37m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[4;39m" << "\033[4;39m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Strikethrough" << setw(CODE) << "\\033[9;30m" << "\033[9;30m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[9;31m" << "\033[9;31m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[9;32m" << "\033[9;32m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[9;33m" << "\033[9;33m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[9;34m" << "\033[9;34m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[9;35m" << "\033[9;35m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[9;36m" << "\033[9;36m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[9;37m" << "\033[9;37m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[9;39m" << "\033[9;39m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Background" << setw(CODE) << "\\033[40m" << "\033[40m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[41m" << "\033[41m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[42m" << "\033[42m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[43m" << "\033[43m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[44m" << "\033[44m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[45m" << "\033[45m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[46m" << "\033[46m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[47m" << "\033[47m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[49m" << "\033[49m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "High Intensity" << setw(CODE) << "\\033[0;90m" << "\033[0;90m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;91m" << "\033[0;91m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;92m" << "\033[0;92m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;93m" << "\033[0;93m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;94m" << "\033[0;94m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;95m" << "\033[0;95m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;96m" << "\033[0;96m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;97m" << "\033[0;97m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;99m" << "\033[0;99m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Bold High" << setw(CODE) << "\\033[1;90m" << "\033[1;90m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "Intensity" << setw(CODE) << "\\033[1;91m" << "\033[1;91m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;92m" << "\033[1;92m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;93m" << "\033[1;93m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;94m" << "\033[1;94m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;95m" << "\033[1;95m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;96m" << "\033[1;96m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;97m" << "\033[1;97m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[1;99m" << "\033[1;99m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "High Intensity" << setw(CODE) << "\\033[0;100m" << "\033[0;100m" << "Black" << "\033[0m" << '\n'
	<< setw(TYPE) << "backgrounds" << setw(CODE) << "\\033[0;101m" << "\033[0;101m" << "Red" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;102m" << "\033[0;102m" << "Green" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;103m" << "\033[0;103m" << "Yellow" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;104m" << "\033[0;104m" << "Blue" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;105m" << "\033[0;105m" << "Purple" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;106m" << "\033[0;106m" << "Cyan" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;107m" << "\033[0;107m" << "White" << "\033[0m" << '\n'
	<< setw(TYPE) << "" << setw(CODE) << "\\033[0;109m" << "\033[0;109m" << "Default" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << '\n'
	<< setw(TYPE) << "Reset" << setw(CODE) << "\\033[0m" << "\033[0m" << '\n'
	<< std::setw(47) << std::setfill('-') << "" << std::setfill(' ') << endl;
}
static void PrintGrammar(void)
{
	cout 
	<< "Format : " << "<escape>" << "\033[37m" << '[' << "\033[0m" << "[<style>;]" << "<color>" << "\033[37m" << 'm' << "\033[0m" << "\n"
	<< "Escape : \\033 or \\x1b or \\e" << '\n'
	<< "Style  : 0 " << "\033[0;39m" << "(Regular)" << "\033[0m" << '\n'
	<< setw(11) << "1 " << "\033[1;39m" << "(Bold)" << "\033[0m" << '\n'
	<< setw(11) << "3 " << "\033[3;39m" << "(Italic)" << "\033[0m" << '\n'
	<< setw(11) << "4 " << "\033[4;39m" << "(Underline)" << "\033[0m" << '\n'
	<< setw(11) << "9 " << "\033[9;39m" << "(Strikethrough)" << "\033[0m" << '\n'
	<< "Color  : " << "3 " << "(Foreground Color)" << '\n'
	<< setw(9) << "" << "\033[40m" << "4 " << "(Background Color)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[30m" << "0 (Black)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[31m" << "1 (Red)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[32m" << "2 (Green)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[33m" << "3 (Yellow)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[34m" << "4 (Blue)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[35m" << "5 (Purple)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[36m" << "6 (Cyan)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[37m" << "7 (White)" << "\033[0m" << '\n'
	<< setw(9) << "" << "\033[39m" << "9 (Default)" << "\033[0m" << '\n';
}
