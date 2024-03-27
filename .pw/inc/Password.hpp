#pragma once

#include <string>

using namespace std;

class Password
{
private:
	string mWords;
	size_t mLength;
	void addBaseWords(void);
	void shuffleString(void);
public:
	Password(int length = 10);
	void	PrintPassword(void);
};
