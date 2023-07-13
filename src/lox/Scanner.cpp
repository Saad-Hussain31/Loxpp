#include "Scanner.hpp"

using namespace lox::interpreter;

Scanner::Scanner(std::string source) : source(source) {}


std::vector<Token> Scanner::scan_tokens() {
    while(!is_at_end()) {
        //at the beginning of next lexeme
        start = current;
        scan_tokens();
    }
    tokens.push_back({TokenType::TOKEN_EOF, "", nullptr, line});
    return tokens;
}


bool Scanner::is_at_end() {
    return current > source.length();
}