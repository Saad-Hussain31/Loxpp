#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>
#include <vector>
#include "Token.hpp"
#include "TokenType.hpp"

namespace lox::interpreter {
class Lox;
class Scanner {
    public:
        Scanner() = default;
        Scanner(std::string source);
        std::vector<Token> scan_tokens();

    private:
        bool is_at_end();
        void scan_each_token();
        char advance();
        void add_token(TokenType type);
        void add_token(TokenType type, void* literal);

    private:
        std::string source;
        std::vector<Token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;
};
} // end lox::interpreter

#endif // SCANNER_H