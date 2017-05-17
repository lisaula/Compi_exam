#include <iostream>

using namespace std;
#include "InputStream.h"
#include "TokenType.h"
#include "Lexer.h"
#include "Parser.h"
int main()
{
    cout << "Hello world!" << endl;

    InputStream *is = new InputStream("(0 + 1 ).1*");
    Lexer *lexer = new Lexer(is);
    //Token* token = lexer->getNextToken();
    Parser *parser = new Parser(lexer);
    parser->parse();
    /*while(token->type != END_OF_FILE){
        cout <<token->lexema<<" "<<token->type<< endl;
        token = lexer->getNextToken();
    }
    cout <<token->lexema<<" "<<token->type<< endl;*/
    return 0;
}
