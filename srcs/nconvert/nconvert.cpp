#include <iostream>
using namespace std;

const string numericUnits[] = {"만", "억", "조", "경", "해", "자", "양", "구", "간", "정", "재", "극", "항하사", "아승기", "나유타", "불가사의", "무량대수"};

static void print(const string& str, const int idx);
static void Converter(string str);

int main(const int ac, const char* av[])
{
    for (int i = 1; i < ac; i++)
        Converter(string(av[i]));
}

void Converter(string str)
{
    int len = str.length();
    int i = 0;

    while (i < len && str[i] == '0')
        ++i;
    
    str = str.substr(i);
    len = str.length();

    bool isNumeric = all_of(str.begin(), str.end(), ::isdigit);
    if (len > 72 || !isNumeric)
    {
        cout << "Cannot be represented\n";
        return ;
    }

    print(str, len - 1);
    cout << '\n';
}

void print(const string& str, const int idx)
{
    if (idx < 0)
        return ;
    print(str, idx - 1);
    cout << str[idx];
    const int tmp = (str.length() -1) - idx;
    if (tmp != 0 && tmp % 4 == 0)
        cout << numericUnits[tmp / 4 - 1] << ' ';
}
