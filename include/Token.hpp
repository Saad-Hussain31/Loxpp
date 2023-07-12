#pragma once
#include <string>
#include "TokenType.hpp"

namespace lox::interpreter {

class Token {
    public:
        TokenType type;
        std::string lexeme;
        void* literal;
        int line;

        Token(TokenType type, std::string lexeme, void* literal, int line) :
        type(type), lexeme(lexeme), literal(literal), line(line)
        {}

        std::string to_str() {
            return std::to_string(static_cast<int>(type)) + " " + lexeme + " " + *static_cast<std::string*>(literal);
        }
};

} //end lox::interpreter