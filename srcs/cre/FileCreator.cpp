#include "FileCreator.hpp"
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>

FileCreator::FileCreator(const string& path)
: mFullPath(path)
, mFileVec()
, mIsDirectory(path[path.length() - 1] == '/')
{
    splitPath();
    for (size_t i = 0; i < mFileVec.size() - 1; i++)
    {
        if (isExist(mFileVec[i]))
            throw "Error: file already exists";
        if (!createDir(mFileVec[i]))
            throw "Error: failed to create directory";
        if (!changeDirectory(mFileVec[i]))
            throw "Error: failed to change directory";
    }

    const string& lastElement = mFileVec.back();
    if (isExist(lastElement))
        throw "Error: file already exists";

    if (mIsDirectory)
    {
        if (!createDir(lastElement))
            throw "Error: failed to create directory";
    }
    else
    {
        if (!createFile(lastElement))
            throw "Error: failed to create file";
    }
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
    if (mFileVec.empty())
        throw "Error: invalid path";
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
