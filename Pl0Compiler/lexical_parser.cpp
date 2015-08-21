#include <cctype>
#include <iostream>
#include <sstream>

#include "global.h"
#include "lexical_parser.h"

using namespace std;

lexical_parser::lexical_parser(sym_table *symt)
	: _symtabl(symt),
	  _iid(0),
	  _inum(0)
{
}

lexical_parser::~lexical_parser()
{
}

void lexical_parser::analysis(const string &word)
{
	string::const_iterator iter = word.begin();
	string::const_iterator end = word.end();
	while (iter != end) {
		if (isalpha(*iter)) { // alpha
			string sym;
			sym.push_back(*iter);
			iter++;
			while (iter != end && isalpha(*iter)) {
				sym.push_back(*iter);
				iter++;
			}
			symbol code = _symtabl->get_keyword(sym);
			if (code == IDENT) { // identity
				add_id(sym);
			} else { // keyword
				add_keyword(sym);
			}
		} else if (isdigit(*iter)) { // number
			string sn;
			sn.push_back(*iter);
			iter++;
			while (iter != end && isdigit(*iter)) {
				sn.push_back(*iter);
				iter++;
			}
			stringstream ss;
			ss << sn;
			int number;
			ss >> number;
			add_number(number);
		} else {
			if (*iter == '>') {
				iter++;
				if (*iter == '=') {
					add_symbol(">=");
					iter++;
				} else {
					add_symbol(">");
				}
			} else if (*iter == '<') {
				iter++;
				if (*iter == '=') {
					add_symbol("<=");
					iter++;
				} else {
					add_symbol("<");
				}
			} else {
				if (iter != end) {
					string tmp;
					tmp.push_back(*iter);
					add_symbol(tmp);
				}
				iter++;
			}
		}
	}
}

void lexical_parser::add_id(const string &id)
{
#ifdef DEBUG
	cout << "Read identity: " << id << " TYPE: IDENT" << endl;
#endif
	_symlist.push_back(make_pair(IDENT, _iid++));
	_idlist.push_back(id);
}

void lexical_parser::add_keyword(const string &keyword)
{
	symbol code = _symtabl->get_keyword(keyword);
#ifdef DEBUG
	cout << "Read keyowrd: " << keyword << " TYPE: " << code << endl;
#endif
	_symlist.push_back(make_pair(code, -1));
}

void lexical_parser::add_number(int num)
{
#ifdef DEBUG
	cout << "Read number: " << num << " TYPE: NUMBER" << endl;
#endif
	_symlist.push_back(make_pair(NUMBER, _inum++));
	_numlist.push_back(num);
}

void lexical_parser::add_symbol(const std::string &sym)
{
	symbol code = _symtabl->get_symbol(sym);
#ifdef DEBUG
	cout << "Read symbol: " << sym << " TYPE: " << code << endl;
#endif
	if (code != ILLEGAL) {
		_symlist.push_back(make_pair(code , -1));
	}
}
