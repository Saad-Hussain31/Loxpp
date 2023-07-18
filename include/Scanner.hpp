#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <vector>
#include <any>
#include "Token.hpp"
#include "TokenType.hpp"

namespace lox::interpreter {
class Scanner {
    public:
        Scanner() = default;
        Scanner(std::string source);
        std::vector<Token> scan_tokens();

    private:
        bool is_at_end();
        void scan_tokens(bool flag);
        char advance();
        void add_token(TokenType type);
        void add_token(TokenType type, std::any literal);
        bool match(char expected);
        char peek(); //look ahead without consuming
        void string();
        void number();
        char peek_next();
        void identifier();

    private:
        std::string source;
        std::vector<Token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;
};
} // end lox::interpreter

#endif // SCANNER_H