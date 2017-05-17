#include "Parser.h"

Parser::Parser(Lexer* l)
{
    lexer = l;
    token = lexer->getNextToken();
    //throw std::invalid_argument( "EXPECTED: digit, letter, or open_parenthesis");
    //ctor
    //cout<<token->lexema<<endl;
}

Parser::~Parser()
{
    //dtor
}
void Parser::parse(){
    regEx();
}
void Parser::regEx(){
    E();
    if(token->type != END_OF_FILE){
        cout<<token->lexema<<" "<<token->type<<endl;
        throw std::invalid_argument( "Not EOF found in regEx");

        }
    cout<<"SUCCESSFUL"<<endl;
}

void Parser::E(){
cout<<"E"<<endl;
    T();
    E_prime();
}

void Parser::E_prime(){
cout<<"EP"<<endl;
    if(token->type == OR){
        token = lexer->getNextToken();
        T();
        E_prime();
    }else{
cout<<"Epsilom"<<endl;
        //epsilon
    }
}

void Parser::T(){
cout<<"T"<<endl;
    F();
    T_prime();
}
void Parser::T_prime(){
cout<<"tP"<<endl;
    if(token->type == CONCAT){
        token = lexer->getNextToken();
        F();
        T_prime();
    }else{
    cout<<"Epsilom"<<endl;
        //epsilon
    }
}

void Parser::F(){
cout<<"f"<<endl;
    if(token->type == KLEENE){
         F_prime();
    }else if(token->type == DIGIT || token->type == LETTER || token->type == OPEN_PARENTHESIS){
        G();
        F_prime();
    }
}
void Parser::F_prime(){
cout<<"fp"<<endl;
    if(token->type == KLEENE){
        token = lexer->getNextToken();
        F();
        F_prime();
    }else{
        //epsilon
        cout<<"Epsilom"<<endl;
    }
}

void Parser::G(){
cout<<"g"<<endl;
    if(token->type!=DIGIT && token->type != LETTER && token->type!=OPEN_PARENTHESIS){
        cout<<token->lexema<<"  "<<token->type<<endl;

        throw std::invalid_argument( "EXPECTED: digit, letter, or open_parenthesis ");
    }
    if(token->type == OPEN_PARENTHESIS){
        token = lexer->getNextToken();
        E();
        if(token->type !=CLOSE_PARENTHESIS)
            throw std::invalid_argument( "EXPECTED: close_parenthesis");
        token = lexer->getNextToken();
    }else{
    cout<<"consumio "<<token->lexema<<endl;
    token = lexer->getNextToken();
    cout<<"tiene "<<token->lexema<<endl;
    }0.
}
