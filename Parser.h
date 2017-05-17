#ifndef PARSER_H
#define PARSER_H
#include <iostream>

using namespace std;
#include "Lexer.h"
class Parser
{
    public:
        Lexer *lexer;
        Token *token;
        void parse();
        void regEx();
        void E();
        void E_prime();
        void T();
        void T_prime();
        void F();
        void F_prime();
        void G();
        Parser(Lexer*);
        virtual ~Parser();
    protected:
    private:
};

#endif // PARSER_H
