#include <iostream>
#include "FileCreator.hpp"

int main(const int ac, const char* av[])
{
    if (ac == 1)
    {
        cerr << "Usage: comp <component name>\n";
        return 1;
    }

    try
    {
        const string path = av[1];
        FileCreator fc(path);
        cout << path << " component created\n";
    }
    catch (const char* e)
    {
        cerr << "comp: " << e << '\n';
        return 1;
    }
    catch (const string& e)
    {
        cerr << "comp: " << e << '\n';
        return 1;
    }
    return 0;
}
