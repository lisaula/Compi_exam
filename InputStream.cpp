#include "InputStream.h"

InputStream::InputStream(char* codigo)
{
    //ctor
    this->code = codigo;
    length = (unsigned)strlen(codigo);
    contador = 0;
}

InputStream::~InputStream()
{
    //dtor
}

char InputStream::getNextSymbol(){
    if(contador < length)
        return code[contador++];
    return '\0';
}
