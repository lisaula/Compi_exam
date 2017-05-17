#ifndef LEXER_H
#define LEXER_H

#include "InputStream.h"
#include "Token.h"
#include <stdexcept>
class Lexer
{
    public:
        InputStream *is;
        char currentSymbol;
        Lexer(InputStream*);
        virtual ~Lexer();
        Token* getNextToken();
    protected:
    private:
};

#endif // LEXER_H
