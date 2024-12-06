#include <iostream>
using namespace std;

static void PrintRainbow(const char* str);
static bool IsKorean(const char c);

int main(const int ac, const char* av[])
{
    for (int i = 1; i < ac; i++)
        PrintRainbow(av[i]);
    return 0;
}

void PrintRainbow(const char* str)
{
    const int rainbow_colors[] = {7, 1, 3, 2, 6, 4, 5};
    size_t idx = 0;

    for (size_t i = 0; i < strlen(str); i++)
    {
        if (IsKorean(str[i]))
            cout << "\033[9" << rainbow_colors[idx++ % 7] << 'm' << str[i++] << str[i++] << str[i];
        else
            cout << "\033[9" << rainbow_colors[idx++ % 7] << 'm' << str[i];
    }
    cout << endl;
}

// https://klkl0.tistory.com/52
bool IsKorean(const char c)
{
    return (c & 0x80);
}
