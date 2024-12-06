#include "FileCreator.hpp"
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>

FileCreator::FileCreator(const string& compName)
{
    string dirName = compName;
    dirName[0] = tolower(dirName[0]);
    const string tsx = compName + ".tsx";
    const string css = compName + ".module.css";

    if (isExist(dirName))
        throw "Error: " + dirName + " directory already exists";
    if (!createDir(dirName))
        throw "Error: failed to create directory";
    if (!changeDirectory(dirName))
        throw "Error: failed to change directory";
    if (!createFile(tsx))
        throw "Error: failed to create file " + tsx;
    if (!createFile(css))
        throw "Error: failed to create file " + css;
}
FileCreator::~FileCreator()
{
}
bool FileCreator::changeDirectory(const string& path)
{
    return (chdir(path.c_str()) == 0);
}
bool FileCreator::createDir(const string& dir)
{
    return (mkdir(dir.c_str(), 0755) == 0);
}
bool FileCreator::createFile(const string& path)
{
    ofstream file(path);
    if (!file.is_open())
    {
        return false;
    }
    file.close();
    return true;
}
bool FileCreator::isExist(const string& path)
{
    return (access(path.c_str(), F_OK) == 0);
}
