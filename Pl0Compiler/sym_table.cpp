#include "common.h"
#include "sym_table.h"

using namespace std;

sym_table::sym_table()
{
	init_keywords();
	init_symbols();
}

sym_table::~sym_table()
{
}

symbol sym_table::get_keyword(const string &sym)
{
	map<string, symbol>::iterator pos = _keywords.find(to_lower(sym));
	if (pos != _keywords.end()) {
		return pos->second;
	}
	else {
		return IDENT;
	}
}

symbol sym_table::get_symbol(const string &sym)
{
	map<string, symbol>::iterator pos = _symbols.find(to_lower(sym));
	if (pos != _symbols.end()) {
		return pos->second;
	}
	else {
		return ILLEGAL;
	}
}

void sym_table::init_keywords()
{
	_keywords.insert(make_pair("begin", BEGINSYM));
	_keywords.insert(make_pair("const", CONSTSYM));
	_keywords.insert(make_pair("int", INTSYM));
	_keywords.insert(make_pair("call", CALLSYM));
	_keywords.insert(make_pair("do", DOSYM));
	_keywords.insert(make_pair("end", ENDSYM));
	_keywords.insert(make_pair("if", IFSYM));
	_keywords.insert(make_pair("odd", ODDSYM));
	_keywords.insert(make_pair("procedure", PROCEDURESYM));
	_keywords.insert(make_pair("then", THENSYM));
	_keywords.insert(make_pair("var", VARSYM));
	_keywords.insert(make_pair("while", WHILESYM));
	_keywords.insert(make_pair("type", TYPESYM));
	_keywords.insert(make_pair("array", ARRAYSYM));
	_keywords.insert(make_pair("of", OFSYM));
	_keywords.insert(make_pair("integer", INTEGERSYM));
	_keywords.insert(make_pair("real", REALSYM));
	_keywords.insert(make_pair("boolean", BOOLEANSYM));
	_keywords.insert(make_pair("function", FUNCTIONSYM));
	_keywords.insert(make_pair("else", ELSESYM));
	_keywords.insert(make_pair("write", WRITESYM));
	_keywords.insert(make_pair("read", READSYM));
	_keywords.insert(make_pair("exit", EXITSYM));
	_keywords.insert(make_pair("or", ORSYM));
	_keywords.insert(make_pair("and", ANDSYM));
	_keywords.insert(make_pair("not", NOTSYM));
	_keywords.insert(make_pair("div", DIVSYM));
	_keywords.insert(make_pair("mod", MODSYM));
	_keywords.insert(make_pair("true", TRUESYM));
	_keywords.insert(make_pair("false", FALSESYM));
}

void sym_table::init_symbols()
{
	_symbols.insert(make_pair("=", ASSIGNSYM));
	_symbols.insert(make_pair(";", SEMICONLONSYM));
	_symbols.insert(make_pair(",", COMMASYM));
	_symbols.insert(make_pair("+", PLUSSYM));
	_symbols.insert(make_pair("-", MIMUSSYM));
	_symbols.insert(make_pair("*", STARSYM));
	_symbols.insert(make_pair("/", DIVIDESYM));
	_symbols.insert(make_pair("#", TAILSYM));
	_symbols.insert(make_pair("<", LTSYM));
	_symbols.insert(make_pair(">", GTSYM));
	_symbols.insert(make_pair("<=", LESYM));
	_symbols.insert(make_pair(">=", GESYM));
	_symbols.insert(make_pair("**", POWERSYM));
	_symbols.insert(make_pair("(", POWERLEFTSYM));
	_symbols.insert(make_pair(")", POWERRIGHTSYM));
	_symbols.insert(make_pair(":", COLONYM));
	_symbols.insert(make_pair("[", BRACKETLEFTSYM));
	_symbols.insert(make_pair("]", BRACKETRIGHTSYM));
}
