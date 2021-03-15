#pragma once
#include "Automaton.h"
#include <string>
#include <cctype>
using namespace std;

class BadComment: public Automaton {
    friend class Token;
private:
    int newLines = 0;
    unsigned int index = 0;
public:
    BadComment(TokenType type) : Automaton(type) {
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
    int Start (string input) {
        index = 0;
        s0(input);
        return index;
    }
    void s0 (string input) {
        if (input.at(index) == '#') {
            index++;
            s1(input);
        }
    }
    void s1 (string input) {
        if (input.at(index) == '|') {
            index++;
            s2(input);
        }
        else {
            index = 0;
        }
    }
    void s2 (string input) {
        if (index == input.size()) {

        }
        else if (input.at(index) == '|') {
            index++;
            s3(input);
        }
        else if (input.at(index) == '\n') {
            index++;
            newLines++;
            s2(input);
        }
        else {
            index++;
            s2(input);
        }

    }
    void s3(string input) {
        if (index == input.size()) {

        }
        else if (input.at(index) == '#') {
            index = 0;
        }
        else if (input.at(index) == '\n') {
            index++;
            newLines++;
            s2(input);
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