#include <iostream>
#include "FileCreator.hpp"

int main(const int ac, const char* av[])
{
    if (ac == 1)
    {
        cout << "Usage: cre <path>\n";
        return 1;
    }

    try
    {
        const string path = av[1];
        FileCreator fc(path);
        fc.Print();
    }
    catch (const FileCreator::InvalidPathException& e)
    {
        cerr << "cre: " << e.what() << ": Invalid file path\n";
    }
    return 0;
}
