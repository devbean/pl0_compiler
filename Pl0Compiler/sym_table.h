#pragma once

#ifndef SYM_TABLE
#define SYM_TABLE

#include <map>
#include <string>

enum symbol
{
	IDENT,
	NUMBER,

	BEGINSYM,
	CONSTSYM,
	INTSYM,
	CALLSYM,
	DOSYM,
	ENDSYM,
	IFSYM,
	ODDSYM,
	PROCEDURESYM,
	THENSYM,
	VARSYM,
	WHILESYM,
	TYPESYM,
	ARRAYSYM,
	OFSYM,
	INTEGERSYM,
	REALSYM,
	BOOLEANSYM,
	FUNCTIONSYM,
	ELSESYM,
	WRITESYM,
	READSYM,
	EXITSYM,

	ORSYM,
	ANDSYM,
	NOTSYM,
	DIVSYM,
	MODSYM,
	TRUESYM,
	FALSESYM,
	ASSIGNSYM,
	SEMICONLONSYM,
	COMMASYM,
	PLUSSYM,
	MIMUSSYM,
	STARSYM,
	DIVIDESYM,
	TAILSYM,
	LTSYM,
	GTSYM,
	LESYM,
	GESYM,
	POWERSYM,
	POWERLEFTSYM,
	POWERRIGHTSYM,
	COLONYM,
	BRACKETLEFTSYM,
	BRACKETRIGHTSYM,

	ILLEGAL = -99
};

class sym_table
{
public:
	sym_table();
	~sym_table();

	symbol get_keyword(const std::string &sym);
	symbol get_symbol(const std::string &sym);
private:
	void init_keywords();
	void init_symbols();

	std::map<std::string, symbol> _keywords;
	std::map<std::string, symbol> _symbols;
};

#endif // SYM_TABLE
