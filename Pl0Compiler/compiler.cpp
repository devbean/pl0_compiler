#include <iostream>

#include "compiler.h"
#include "lexical_parser.h"
#include "sym_table.h"

using namespace std;

compiler::compiler(const std::string &src)
	: symtabl(new sym_table),
	  lexparser(new lexical_parser(symtabl))
{
	sin = ifstream("demo.pl0", ios::in);
	if (!sin.is_open())
	{
		cerr << "Cannot read source file. Compiler exit.";
	}
}

compiler::~compiler()
{
	sin.close();
}

void compiler::compile()
{
	string word;
	while (sin >> word)
	{
		lexparser->analysis(word);
	}
}
