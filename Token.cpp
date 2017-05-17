#include "Token.h"

Token::Token(char lexema, TokenType type)
{
    //ctor
    this->lexema = lexema;
    this->type = type;
}

Token::~Token()
{
    //dtor
}
