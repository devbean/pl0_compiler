#include <cstdlib>

#include "compiler.h"

using namespace std;

int main(int argc, char *argv[])
{
	compiler c("demo.pl0");
	c.compile();

	system("PAUSE");
	return 0;
}