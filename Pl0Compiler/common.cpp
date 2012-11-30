#include <algorithm>
#include <cctype>

#include "common.h"

using namespace std;

string to_lower(const string &str)
{
	string tmp(str);
    transform(tmp.begin(),
              tmp.end(),
              tmp.begin(),
              tolower);
	return tmp;
}

bool is_digit(char c)
{
	return '0' <= c && c <= '9';
}

bool is_alpha(char c)
{
	return ('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z');
}
