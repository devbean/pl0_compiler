#pragma once

#ifndef TABLE
#define TABLE

#include <list>
#include <string>

#include "global.h"

enum object
{
	constant,
	variable,
	procedure
};

struct table_item
{
	std::string name;
	object kind;
	union {
		int val;
		struct {
			int level;
			int adr;
			int size;
		};
	};
};

class table
{
public:
	table();

	void Enter(object k);
	int Position(char *id);
	int TableIndex() { return _tx[_lev]; }
public:
	std::list<table_item> _table;
private:
	int _tx[MAX_NESTED_LEVEL + 1];
	int _lev;
};

#endif // TABLE
