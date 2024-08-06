#include "ANSI.hpp"

ANSI::ANSI()
: mEscape(ESCAPE[0])
, mStyleType(REGULAR)
, mColorType(FG)
, mColor(DEFAULT) {}

ANSI::~ANSI() {}

string ANSI::Reset()
{
    return mEscape + "[0m";
}

// ostream& operator<<(ostream& os, const ANSI& ansi)
// {
//     os << ansi.mEscape << "[" << ansi.mStyleType << ";"
//     << ansi.mColorType << ansi.mColor << "m";
//     return os;
// }
