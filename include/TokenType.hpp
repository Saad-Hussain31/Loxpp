#pragma once

namespace lox::interpreter {

/**
 * @enum TokenType
 * @brief Represents the types of tokens in the Lox programming language.
 *
 * Each token in the Lox language is classified into one of these TokenType categories.
 * The TokenType determines the role and meaning of the token in the source code.
 */
enum class TokenType {
    // Single-character tokens.
    LEFT_PAREN,     ///< '('
    RIGHT_PAREN,    ///< ')'
    LEFT_BRACE,     ///< '{'
    RIGHT_BRACE,    ///< '}'
    COMMA,          ///< ','
    DOT,            ///< '.'
    MINUS,          ///< '-'
    PLUS,           ///< '+'
    SEMICOLON,      ///< ';'
    SLASH,          ///< '/'
    STAR,           ///< '*'

    // One or two character tokens.
    BANG,           ///< '!'
    BANG_EQUAL,     ///< '!='
    EQUAL,          ///< '='
    EQUAL_EQUAL,    ///< '=='
    GREATER,        ///< '>'
    GREATER_EQUAL,  ///< '>='
    LESS,           ///< '<'
    LESS_EQUAL,     ///< '<='

    // Literals.
    IDENTIFIER,     ///< Identifiers, e.g., variable names.
    STRING,         ///< String literals.
    NUMBER,         ///< Numeric literals.

    // Keywords.
    AND,            ///< 'and' keyword
    CLASS,          ///< 'class' keyword
    ELSE,           ///< 'else' keyword
    FALSE,          ///< 'false' keyword
    FUN,            ///< 'fun' keyword
    FOR,            ///< 'for' keyword
    IF,             ///< 'if' keyword
    NIL,            ///< 'nil' keyword
    OR,             ///< 'or' keyword
    PRINT,          ///< 'print' keyword
    RETURN,         ///< 'return' keyword
    SUPER,          ///< 'super' keyword
    THIS,           ///< 'this' keyword
    TRUE,           ///< 'true' keyword
    VAR,            ///< 'var' keyword
    WHILE,          ///< 'while' keyword

    END_OF_FILE,    ///< Represents the end of the source file.
    UNKNOWN         ///< Represents an unknown or unrecognized token.
};

} //end lox::interpreter
