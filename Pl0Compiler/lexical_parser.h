#pragma once

#ifndef LEXICAL_PARSER
#define LEXICAL_PARSER

#include <list>

#include "sym_table.h"

typedef std::list<std::pair<std::string, int> > symbol_list;
typedef std::list<std::string>                  id_list;
typedef std::list<int>                          number_list;

class lexical_parser
{
public:
	lexical_parser(sym_table *symt);
	~lexical_parser();

	void parsing(const std::string &word);
private:
	void add_id(const std::string &id);
	void add_keyword(const std::string &keyword);
	void add_number(int num);
	void add_symbol(const std::string &sym);

	sym_table*  _symtabl;
	id_list     _idlist;
	symbol_list _symlist;
	number_list _numlist;

	int         _iid;
	int         _inum;
};

#endif // LEXICAL_PARSER
