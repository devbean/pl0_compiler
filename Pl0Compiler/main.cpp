#include <cstdlib>
#include <iostream>
#include <fstream>

#include "sym_table.h"
#include "lexical_parser.h"

using namespace std;

int main(int argc, char *argv[])
{
	sym_table symtabl;
	lexical_parser lexparser(symtabl);

	ifstream sin("demo.pl0", ios::in);
	if (!sin) {
		cerr << "Cannot read source file. Compiler exit.";
	} else {
		string word;  
		while (sin >> word)
		{
			lexparser.parsing(word);
		}
		sin.close();
	}

	system("PAUSE");
	return 0;
}