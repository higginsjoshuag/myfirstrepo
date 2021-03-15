#pragma once
#include "Token.h"
#include <string>
using namespace std;

class Automaton {

protected:
    friend class Lexer;
    int newLines = 0;
    TokenType type;
public:
    Automaton(TokenType type) {
        this->type = type;
    }
    virtual ~Automaton() {}

    virtual int Read(const string& input) = 0;
    Token* CreateToken(string input, int lineNumber) {
        return new Token(type, input, lineNumber);
    }
    virtual int NewLinesRead() const {
        return newLines;
    }

};
