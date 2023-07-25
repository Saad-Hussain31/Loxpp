/**
 * @file Scanner.hpp
 *
 * @brief Declaration of the Scanner class, used for tokenizing source code.
 */

#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <map>
#include "Token.hpp"
#include "TokenType.hpp"

namespace lox::interpreter {

/**
 * @brief A class responsible for scanning source code and producing a vector of tokens.
 */
class Scanner {
public:
    /**
     * @brief Default constructor for the Scanner class.
     */
    Scanner() = default;

    /**
     * @brief Parameterized constructor for the Scanner class.
     *
     * @param source The source code as a string that needs to be scanned.
     */
    Scanner(std::string source);

    /**
     * @brief Scans the source code and returns a vector of tokens.
     *
     * @return std::vector<Token> A vector containing the scanned tokens.
     */
    std::vector<Token> scan_tokens();

private:
    /**
     * @brief Checks if the scanner has reached the end of the source code.
     *
     * @return bool True if the scanner has reached the end, false otherwise.
     */
    bool is_at_end();

    /**
     * @brief Scans the next token in the source code.
     */
    void scan_token();

    /**
     * @brief Advances to the next character in the source code and returns it.
     *
     * @return char The next character in the source code.
     */
    char advance();

    /**
     * @brief Adds a token with the given type to the tokens vector.
     *
     * @param type The type of the token to be added.
     */
    void add_token(TokenType type);

    /**
     * @brief Adds a token with the given type and literal value to the tokens vector.
     *
     * @param type The type of the token to be added.
     * @param literal The literal value associated with the token.
     */
    void add_token(TokenType type, std::any literal);

    /**
     * @brief Matches the current character with the expected character.
     *
     * If the characters match, the scanner advances to the next character.
     *
     * @param expected The character to be matched against the current character.
     * @return bool True if the characters match, false otherwise.
     */
    bool match(char expected);

    /**
     * @brief Returns the next character in the source code without consuming it.
     *
     * @return char The next character in the source code.
     */
    char peek();

    /**
     * @brief Scans a string token in the source code.
     */
    void string();

    /**
     * @brief Scans a number token in the source code.
     */
    void number();

    /**
     * @brief Returns the character after the current character without consuming it.
     *
     * @return char The character after the current character in the source code.
     */
    char peek_next();

    /**
     * @brief Scans an identifier token in the source code.
     */
    void identifier();

    /**
    * @brief Scans a c-style block comment token in the source code.
    */
    void block_comment();

private:
    std::string source;             /**< The source code to be scanned. */
    std::vector<Token> tokens;      /**< Vector to store the scanned tokens. */
    int start = 0;                  /**< Index of the beginning of the current lexeme. */
    int current = 0;                /**< Index of the current character being processed. */
    int line = 1;                   /**< Current line number in the source code. */
    static std::map<std::string, TokenType> keywords; /**< Map of reserved keywords and their corresponding token types. */
};

} // end lox::interpreter

#endif // SCANNER_H
