#pragma once

#ifndef COMPILER
#define COMPILER

#include <fstream>

class sym_table;
class lexical_parser;

class compiler
{
public:
	compiler(const std::string &src);
	~compiler();

	void compile();

private:
	std::ifstream sin;

	sym_table      *symtabl;
	lexical_parser *lexparser;
};

#endif // COMPILER
