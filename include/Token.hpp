#pragma once

#include <string>
#include <any>
#include "TokenType.hpp"

namespace lox::interpreter {

/**
 * @class Token
 * @brief Represents a token in the Lox programming language.
 *
 * A token is a fundamental building block of the Lox language. It represents a lexical element
 * in the source code and contains information such as its type, lexeme, literal value, and the line number
 * where it appears in the source code.
 */
class Token {
public:
    /**
     * @brief Constructor to create a new Token instance.
     * @param type The TokenType of the token.
     * @param lexeme The lexeme (actual text) of the token.
     * @param literal The literal value associated with the token.
     * @param line The line number where the token appears in the source code.
     */
    Token(TokenType type, std::string lexeme, std::any literal, int line)
        : type(type), lexeme(lexeme), literal(literal), line(line) {}

    /**
     * @brief Convert the Token to a string representation for debugging purposes.
     * @return A string representing the Token's type, lexeme, and literal value.
     */
    std::string to_str() {
        return std::to_string(static_cast<int>(type)) + " " + lexeme +
               " " + std::any_cast<std::string>(literal);
    }

public:
    TokenType type; ///< The type of the token.
    std::string lexeme; ///< The lexeme (actual text) of the token.
    std::any literal; ///< The literal value associated with the token.
    int line; ///< The line number where the token appears in the source code.
};

} //end lox::interpreter
