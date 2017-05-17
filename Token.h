#ifndef TOKEN_H
#define TOKEN_H
#include "TokenType.h"

class Token
{
    public:
        char lexema;
        TokenType type;
        Token(char lexema, TokenType type);
        virtual ~Token();
    protected:
    private:
};

#endif // TOKEN_H
