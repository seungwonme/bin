#include "FileCreator.hpp"
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <errno.h>

FileCreator::FileCreator(const string& path)
: mFullPath(path)
, mFileVec()
{
    splitPath();
}
FileCreator::~FileCreator()
{
}
void FileCreator::Print(void) const
{
    for (vector<const string>::const_iterator it = mFileVec.begin(); it != mFileVec.end(); ++it)
    {
        cout << *it << '\n';
    }
}
void FileCreator::splitPath(void)
{
    istringstream iss(mFullPath);
    string tk;

    while (getline(iss, tk, '/'))
    {
        if (!tk.empty())
        {
            mFileVec.push_back(tk);
        }
    }
}
bool FileCreator::changeDirectory(const string& path)
{
    return (chdir(path.c_str()) == 0);
}
bool FileCreator::createDir(const string& path)
{
    return (mkdir(path.c_str(), 755) == 0);
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
    return access(path.c_str(), F_OK);
}
