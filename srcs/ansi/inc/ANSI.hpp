#ifndef ANSI_HPP
#define ANSI_HPP

#include <string>
using namespace std;

const string ESCAPE[3] = {
    "\033", 
    "\x1b", 
    "\e"
};

namespace color
{
    const char* FG_BLACK = "\033[90m";
    const char* FG_RED = "\033[91m";
    const char* FG_GREEN = "\033[92m";
    const char* FG_YELLOW = "\033[93m";
    const char* FG_BLUE = "\033[94m";
    const char* FG_MAGENTA = "\033[95m";
    const char* FG_CYAN = "\033[96m";
    const char* FG_WHITE = "\033[97m";
    const char* FG_DEFAULT = "\033[39m";

    const char* DEFAULT = "\033[0m";
    const char* BOLD = "\033[1m";
    const char* ITALIC = "\033[3m";
    const char* UNDERLINE = "\033[4m";
    const char* REVERSE = "\033[7m";
    const char* STRIKETHROUGH = "\033[9m";

    const char* BG_BLACK = "\033[100m";
    const char* BG_RED = "\033[101m";
    const char* BG_GREEN = "\033[102m";
    const char* BG_YELLOW = "\033[103m";
    const char* BG_BLUE = "\033[104m";
    const char* BG_MAGENTA = "\033[105m";
    const char* BG_CYAN = "\033[106m";
    const char* BG_WHITE = "\033[107m";
    const char* BG_DEFAULT = "\033[49m";

    const char* RESET = "\033[0m";
}

enum class eStyleType
{
    REGULAR = 0,
    BOLD = 1,
    FAINT = 2,
    ITALIC = 3,
    UNDERLINE = 4,
    BLINK = 5,
    RAPID_BLINK = 6,
    INVERSE = 7,
    CONCEAL = 8,
    STRIKE_THROUGH = 9
};

enum class eColorType
{
    FG = 0,
    BG = 1
};

enum class eColor
{
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7,
    DEFAULT = 9
};

class ANSI
{
private:
    const string& mEscape;
    eStyleType mStyleType;
    eColorType mColorType;
    eColor mColor;
public:
    ANSI();
    ~ANSI();
    string Reset();
    friend ostream& operator<<(ostream& os, const ANSI& ansi)
    {
        os << ansi.mEscape << "[" << ansi.mStyleType << ";"
        << ansi.mColorType << ansi.mColor << "m";
        return os;
    }
};

#endif
