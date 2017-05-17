#ifndef INPUTSTREAM_H
#define INPUTSTREAM_H
#include <string.h>

class InputStream
{
    public:
        unsigned int contador, length;

        char* code;
        InputStream(char* code);
        char getNextSymbol();
        virtual ~InputStream();
    protected:
    private:
};

#endif // INPUTSTREAM_H
