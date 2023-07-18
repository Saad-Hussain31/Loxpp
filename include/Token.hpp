#pragma once
#include <string>
#include <any>
#include "TokenType.hpp"

namespace lox::interpreter {

class Token {
    public:
        Token(TokenType type, std::string lexeme, std::any literal, int line) :
        type(type), lexeme(lexeme), literal(literal), line(line)
        {}

        std::string to_str() {
            return std::to_string(static_cast<int>(type)) + " " + lexeme +
             " " + std::any_cast<std::string>(literal);
        }
    public:
        TokenType type;
        std::string lexeme;
        std::any literal;
        int line;
};

} //end lox::interpreter