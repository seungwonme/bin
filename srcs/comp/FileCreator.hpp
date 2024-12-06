#ifndef FILE_CREATOR_HPP
#define FILE_CREATOR_HPP

#include <string>
#include <vector>

using namespace std;

class FileCreator
{
private:
    bool changeDirectory(const string& path);
    bool createFile(const string& path);
    bool isExist(const string& path);
    bool createDir(const string& dir);

public:
    FileCreator(const string& compName);
    ~FileCreator();
};

#endif
