#ifndef FILE_CREATOR_HPP
#define FILE_CREATOR_HPP

#include <string>
#include <vector>

using namespace std;

class FileCreator
{
private:
    const string mFullPath;
    vector<const string> mFileVec;
    void splitPath(void);
    bool changeDirectory(const string& path);
    bool createFile(const string& path);
    bool isExist(const string& path);
    bool createDir(const string& dir);

public:
    FileCreator(const string& path);
    ~FileCreator(void);
    void Print(void) const;
};

#endif
