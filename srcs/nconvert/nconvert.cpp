#include <iostream>
using namespace std;

const string numericUnits[] = {"만", "억", "조", "경", "해", "자", "양", "구", "간", "정", "재", "극", "항하사", "아승기", "나유타", "불가사의", "무량대수"};

static void print(const string& str, const int idx);
static void Converter(const string& str);
static void print_rainbow(const int idx);

int main(const int ac, const char* av[])
{
    for (int i = 1; i < ac; i++)
    {
        print_rainbow(i - 1);
        Converter(string(av[i]));
    }
}

void print_rainbow(const int idx)
{
    const int rainbow_colors[] = {7, 1, 3, 2, 6, 4, 5};
    cout << "\033[9" << rainbow_colors[(idx) % 7] << 'm';
}

void Converter(const string& str)
{
    const int len = str.length();
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
        cout << numericUnits[tmp / 4 - 1];
}
