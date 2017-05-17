#include "Lexer.h"

Lexer::Lexer(InputStream *input)
{
    is = input;
    currentSymbol = is->getNextSymbol();
    //ctor
}

Lexer::~Lexer()
{
    //dtor
}

Token* Lexer::getNextToken(){
    while ((int)currentSymbol == 32 || currentSymbol == '\r' || currentSymbol == '\n' || currentSymbol == '\t')
    {
        currentSymbol = is->getNextSymbol();
    }

    if(((int)currentSymbol >= 65 && (int)currentSymbol <= 90) ||
      ((int)currentSymbol >= 97 && (int)currentSymbol <= 122)) {
        char symbol = currentSymbol;
        currentSymbol = is->getNextSymbol();
        return new Token(symbol, LETTER);
    }
    if( (int)currentSymbol >= 48 && (int)currentSymbol <=57 ){
        char symbol = currentSymbol;
        currentSymbol = is->getNextSymbol();
        return new Token(symbol, DIGIT);
    }
    if(currentSymbol == '('){
        char symbol = currentSymbol;
        currentSymbol = is->getNextSymbol();
        return new Token(symbol, OPEN_PARENTHESIS);
    }
    if(currentSymbol == ')'){
        char symbol = currentSymbol;
        currentSymbol = is->getNextSymbol();
        return new Token(symbol, CLOSE_PARENTHESIS);
    }
    if(currentSymbol == '.'){
        char symbol = currentSymbol;
        currentSymbol = is->getNextSymbol();
        return new Token(symbol, CONCAT);
    }
    if(currentSymbol == '+'){
        char symbol = currentSymbol;
        currentSymbol = is->getNextSymbol();
        return new Token(symbol, OR);
    }
    if(currentSymbol == '*'){
        char symbol = currentSymbol;
        currentSymbol = is->getNextSymbol();
        return new Token(symbol, KLEENE);
    }
    if(currentSymbol == '\0'){
        char symbol = currentSymbol;
        currentSymbol = is->getNextSymbol();
        return new Token(symbol, END_OF_FILE);
    }

    throw std::invalid_argument( "Symbol not supported: "+currentSymbol );
}
