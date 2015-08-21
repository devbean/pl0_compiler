#pragma once

#ifndef SYNTACTIC_OARSER
#define SYNTACTIC_PARSER

class lexical_parser;

class syntactic_parser
{
public:
	syntactic_parser(lexical_parser *lex_parser);
	~syntactic_parser();

private:
	lexical_parser *lex_parser;
};

#endif // SYNTACTIC_PARSER
