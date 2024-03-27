#pragma once

#include <string>

using namespace std;

class Password
{
private:
	string mCharacters;
	size_t mLength;
	void addAlpha(void);
	void addDigits(void);
	void addSymbols(void);
	void shuffleString(void);
public:
	Password();
	void	SetLength(size_t length);
	void	PrintPassword(void);
};

void CopyToClipboard(const std::string& text);
void LogPasswordToCSV(const std::string &password);
