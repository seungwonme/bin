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
    bool addContents(const string& fileName, const string& compName, bool withCSS);

public:
    FileCreator(const string& compName, const bool withCSS);
    ~FileCreator();
};

/* ANSI Escape Codes */
namespace aec
{
    namespace fg
    {
        const string BLACK = "\033[30m";
        const string RED = "\033[31m";
        const string GREEN = "\033[32m";
        const string YELLOW = "\033[33m";
        const string BLUE = "\033[34m";
        const string MAGENTA = "\033[35m";
        const string CYAN = "\033[36m";
        const string WHITE = "\033[37m";
    }  // namespace fg
    namespace bg
    {
        const string BLACK = "\033[40m";
        const string RED = "\033[41m";
        const string GREEN = "\033[42m";
        const string YELLOW = "\033[43m";
        const string BLUE = "\033[44m";
        const string MAGENTA = "\033[45m";
        const string CYAN = "\033[46m";
        const string WHITE = "\033[47m";
    }  // namespace bg
    namespace st
    {
        const string REGULAR = "\033[0m";
        const string BOLD = "\033[1m";
        const string FAINT = "\033[2m";
        const string ITALIC = "\033[3m";
        const string UNDERLINE = "\033[4m";
        const string BLINK = "\033[5m";
        const string RAPID_BLINK = "\033[6m";
        const string REVERSE = "\033[7m";
        const string HIDDEN = "\033[8m";
        const string STRIKE_THROUGH = "\033[9m";
    }  // namespace st
    const string RESET = "\033[0m";
}  // namespace aec

#endif
