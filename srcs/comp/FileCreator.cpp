#include "FileCreator.hpp"
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>

FileCreator::FileCreator(const string& compName, const bool withCSS)
{
    string dirName = compName;
    dirName[0] = tolower(dirName[0]);
    const string fileName = compName + ".tsx";
    const string moduleCss = withCSS ? compName + ".module.css" : "";

    if (isExist(dirName))
        throw "Error: " + dirName + " directory already exists";
    if (!createDir(dirName))
        throw "Error: failed to create " + dirName + " directory";
    if (!changeDirectory(dirName))
        throw "Error: failed to change " + dirName + " directory";
    if (!createFile(fileName))
        throw "Error: failed to create file " + fileName;
    if (!addContents(fileName, compName, withCSS))
        throw "Error: failed to add contents to " + fileName;
    if (withCSS && !createFile(moduleCss))
        throw "Error: failed to create file " + moduleCss;
    if (!changeDirectory(".."))
        throw "Error: failed to change to parent directory";
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
bool FileCreator::addContents(const string& fileName, const string& compName, bool withCSS)
{
    ofstream file(fileName, ios::app);
    if (!file.is_open())
    {
        return false;
    }
    if (withCSS)
    {
        file << "import classes from './" << compName << ".module.css';\n";
        file << "\n";
    }
    file << "export default function " << compName << "() {\n";
    file << "  return (\n";
    file << "    \n";
    file << "  );\n";
    file << "}";
    file.close();
    if (file.fail())
    {
        return false;
    }
    return true;
}
