#pragma once

#ifndef SYM_TABLE
#define SYM_TABLE

#include <map>
#include <string>

class sym_table
{
public:
	static const std::string IDENT;
	static const std::string NUMBER;

	sym_table();
	~sym_table();

	std::string get_keyword(const std::string &sym);
	std::string get_symbol(const std::string &sym);
private:
	void init_keywords();
	void init_symbols();

	std::map<std::string, std::string> _keywords;
	std::map<std::string, std::string> _symbols;
};

#endif // SYM_TABLE
