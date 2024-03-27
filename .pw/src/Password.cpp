#include "Password.hpp"
#include <iostream>
#include <random>

using namespace std;

void CopyToClipboard(const string& text);

Password::Password(int length)
: mWords("") 
, mLength(length)
{
	addBaseWords();
	string specialSymbols("!@#$%%^&*_-+=().,?<>;:[]");
	mWords += specialSymbols;
	shuffleString();
}
void	Password::PrintPassword(void)
{
	if (mLength > mWords.length())
	{
		throw "\033[0;31mError\nPassword length is too long !\033[0m";
	}
	CopyToClipboard(mWords.substr(0, mLength));
	cout << mWords.substr(0, mLength) << endl;
}
void Password::addBaseWords(void)
{
	// Digits
	for (char word = '0'; word <= '9'; word++)
	{
		mWords += word;
	}
	// Lowercase
	for (char word = 'a'; word <= 'z'; word++)
	{
		mWords += word;
	}
	// Uppercase
	for (char word = 'A'; word <= 'Z'; word++)
	{
		mWords += word;
	}
}
void Password::shuffleString(void)
{
	string newWords("");

	while (!mWords.empty())
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, mWords.length() - 1);

		size_t idx = dis(gen);
		newWords += mWords[idx];
		mWords.erase(idx, 1);
	}
	mWords = newWords;
}
