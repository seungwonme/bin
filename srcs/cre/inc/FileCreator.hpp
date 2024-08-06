#ifndef FILE_CREATOR_HPP
#define FILE_CREATOR_HPP

#include <exception>
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
    bool createDir(const string& path);
    bool isExist(const string& path);

public:
    FileCreator(const string& path);
    ~FileCreator(void);
    void Print(void) const;

    class InvalidPathException : public std::exception
    {
    private:
        const string mTarget;
    public:
        InvalidPathException(const string& target)
        : mTarget(target) {};
        const char* what() const noexcept override
        {
            return mTarget.c_str();
        }
    };
};

#endif
