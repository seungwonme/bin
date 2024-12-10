#include <iostream>
#include "FileCreator.hpp"

int main(const int ac, const char* av[])
{
    if (ac == 1)
    {
        cerr << aec::fg::RED << "Usage: comp <component name>" << aec::RESET << endl;
        return 1;
    }

    size_t cur = 1;
    bool withCSS = false;
    if (string(av[1]) == "--css" || string(av[1]) == "-c")
    {
        withCSS = true;
        cur++;
    }

    for (int i = cur; i < ac; i++)
    {
        try
        {
            const string compName = av[i];
            FileCreator fc(compName, withCSS);
            cout << compName << " component created\n";
        }
        catch (const string& e)
        {
            cerr << aec::fg::RED << "comp: " << e << aec::RESET << endl;
            return 1;
        }
    }

    return 0;
}
