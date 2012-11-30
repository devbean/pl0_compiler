#include "common.h"
#include "sym_table.h"

using namespace std;

const std::string sym_table::IDENT = "IDENT";
const std::string sym_table::NUMBER = "NUMBER";

sym_table::sym_table()
{
	init_keywords();
	init_symbols();
}

sym_table::~sym_table()
{
}

string sym_table::get_keyword(const string &sym)
{
	map<string, string>::iterator pos = _keywords.find(to_lower(sym));
	if (pos != _keywords.end()) {
		return pos->second;
	} else {
		return IDENT;
	}
}

string sym_table::get_symbol(const string &sym)
{
	map<string, string>::iterator pos = _symbols.find(to_lower(sym));
	if (pos != _symbols.end()) {
		return pos->second;
	} else {
		return string();
	}
}

void sym_table::init_keywords()
{
	_keywords.insert(pair<string, string>("begin", "BEGINSYM"));
	_keywords.insert(pair<string, string>("begin", "BEGINSYM"));
    _keywords.insert(pair<string, string>("const", "CONSTSYM"));
    _keywords.insert(pair<string, string>("int", "CONSTSYM"));
    _keywords.insert(pair<string, string>("call", "CALLSYM"));
    _keywords.insert(pair<string, string>("do", "DOSYM"));
    _keywords.insert(pair<string, string>("end", "ENDSYM"));
    _keywords.insert(pair<string, string>("if", "IFSYM"));
    _keywords.insert(pair<string, string>("odd", "ODDSYM"));
    _keywords.insert(pair<string, string>("procedure", "PROCEDURESYM"));
    _keywords.insert(pair<string, string>("then", "THENSYM"));
    _keywords.insert(pair<string, string>("var", "VARSYM"));
    _keywords.insert(pair<string, string>("while", "WHILESYM"));
    _keywords.insert(pair<string, string>("type", "TYPESYM"));
    _keywords.insert(pair<string, string>("array", "ARRAYSYM"));
    _keywords.insert(pair<string, string>("of", "OFSYM"));
    _keywords.insert(pair<string, string>("integer", "INTEGERSYM"));
    _keywords.insert(pair<string, string>("real", "REALSYM"));
    _keywords.insert(pair<string, string>("boolean", "BOOLENASYM"));
    _keywords.insert(pair<string, string>("function", "FUNCTIONSYM"));
    _keywords.insert(pair<string, string>("else", "ELSESYM"));
    _keywords.insert(pair<string, string>("write", "WRITESYM"));
    _keywords.insert(pair<string, string>("read", "READSYM"));
    _keywords.insert(pair<string, string>("exit", "EXITSYM"));
    _keywords.insert(pair<string, string>("or", "ORSYM"));
    _keywords.insert(pair<string, string>("and", "ANDSYM"));
    _keywords.insert(pair<string, string>("not", "NOTSYM"));
    _keywords.insert(pair<string, string>("div", "DIVSYM"));
    _keywords.insert(pair<string, string>("mod", "MODSYM"));
    _keywords.insert(pair<string, string>("true", "TRUESYM"));
    _keywords.insert(pair<string, string>("false", "FALSESYM"));
}

void sym_table::init_symbols()
{
	_symbols.insert(pair<string, string>("=", "ASSIGNSYM"));
    _symbols.insert(pair<string, string>(";", "SEMICONLONSYM"));
    _symbols.insert(pair<string, string>(",", "COMMASYM"));
    _symbols.insert(pair<string, string>("+", "PLUSSYM"));
    _symbols.insert(pair<string, string>("-", "MIMUSSYM"));
    _symbols.insert(pair<string, string>("*", "STARSYM"));
    _symbols.insert(pair<string, string>("/", "DIVIDESYM"));
    _symbols.insert(pair<string, string>("#", "TAILSYM"));
    _symbols.insert(pair<string, string>("<", "LETHSYM"));
    _symbols.insert(pair<string, string>(">", "GRTHSYM"));
    _symbols.insert(pair<string, string>("<=", "LEEQSYM"));
    _symbols.insert(pair<string, string>(">=", "GREQSYM"));
    _symbols.insert(pair<string, string>("**", "POWERSYM"));
    _symbols.insert(pair<string, string>("(", "POWERLEFTSYM"));
    _symbols.insert(pair<string, string>(")", "POWERRIGHTSYM"));
    _symbols.insert(pair<string, string>(":", "COLONYM"));
    _symbols.insert(pair<string, string>("[", "BRACKETLEFTSYM"));
    _symbols.insert(pair<string, string>("]", "BRACKETRIGHTSYM"));
}
