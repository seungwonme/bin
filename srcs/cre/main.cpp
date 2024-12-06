#include <iostream>
#include "FileCreator.hpp"

int main(const int ac, const char* av[])
{
    if (ac == 1)
    {
        cerr << "Usage: cre <path>\n";
        return 1;
    }

    try
    {
        const string path = av[1];
        FileCreator fc(path);
        fc.Print();
    }
    catch (const char* e)
    {
        cerr << "cre: " << e << '\n';
        return 1;
    }
    return 0;
}
