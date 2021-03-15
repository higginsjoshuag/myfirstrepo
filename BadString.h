#pragma once
#include "Automaton.h"
#include <string>
#include <cctype>
using namespace std;

class BadString: public Automaton {
    friend class Token;
private:
    int newLines = 0;
    unsigned int index = 0;
public:
    BadString(TokenType type) : Automaton(type) {
    }
    int Read(const std::string& input) {
        index = 0;
        newLines = 0;
        if (input == "") {
            return index;
        }
        index = Start(input);
        return index;
    }
    int Start(string input) {
        s0(input);
        return index;
    }
    void s0 (string input) {
        if (input.at(index) == '\'') {
            index++;
            s1(input);
        }
    }
    void s1 (string input) {
        if (index == input.size()) {
        }
        else if (input.at(index) == '\'') {
            index++;
            s2(input);
        }
        else if (input.at(index) == '\n') {
            newLines++;
            index++;
            s1(input);
        }
        else {
            index++;
            s1(input);
        }
    }
    void s2 (string input) {
        if (index == input.size()) {
            index = 0;
        }
        else if (input.at(index) == '\'') {
            index++;
            s1(input);
        }
        else if (input.at(index) == ' ' || input.at(index) == '\t' || input.at(index) == '\n') {
            index = 0;
        }
        else {
            index++;
            s2(input);
        }
    }
    int NewLinesRead() const {
        return newLines;
    }
};