#include "Password.hpp"
#include <iostream>
#include <random>

using namespace std;

Password::Password()
: mCharacters("") 
, mLength(12)
{
	addDigits();
	addAlpha();
	addSymbols();
	shuffleString();
}
void	Password::SetLength(size_t length)
{
	mLength = length;
}
void	Password::PrintPassword(void)
{
	if (mLength > mCharacters.length())
	{
		throw "\033[0;31mError\nPassword length is too long !\033[0m";
	}

	const string password = mCharacters.substr(0, mLength);
	CopyToClipboard(password);
	LogPasswordToCSV(password);
}
void Password::addDigits(void)
{
	// Digits
	for (char word = '0'; word <= '9'; word++)
	{
		mCharacters += word;
	}
}
void Password::addAlpha(void)
{
	// Lowercase
	for (char word = 'a'; word <= 'z'; word++)
	{
		mCharacters += word;
	}
	// Uppercase
	for (char word = 'A'; word <= 'Z'; word++)
	{
		mCharacters += word;
	}
}
void Password::addSymbols(void)
{
	string specialSymbols("~!@#$%^&*-_+=:;,.");
	mCharacters += specialSymbols;
}
void Password::shuffleString(void)
{
	string newWords("");

	while (!mCharacters.empty())
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, mCharacters.length() - 1);

		size_t idx = dis(gen);
		newWords += mCharacters[idx];
		mCharacters.erase(idx, 1);
	}
	mCharacters = newWords;
}
