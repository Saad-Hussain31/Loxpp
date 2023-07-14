#include "Lox.hpp"
#include "Scanner.hpp"


using namespace lox::interpreter;

Scanner::Scanner(std::string source) : source(source) {}

std::vector<Token> Scanner::scan_tokens() {
    while(!is_at_end()) {
        //at the beginning of next lexeme
        start = current;
        scan_each_token();
    }
    tokens.push_back(Token{TokenType::END_OF_FILE, "", nullptr, line});
    return tokens;
}

bool Scanner::is_at_end() {
    return current > source.length();
}

void Scanner::scan_each_token() {
    char c = advance();
    switch(c) {
        case '(' : add_token(TokenType::LEFT_PAREN); break;
        case ')' : add_token(TokenType::RIGHT_PAREN); break;
        case '{' : add_token(TokenType::LEFT_BRACE); break;
        case '}' : add_token(TokenType::RIGHT_BRACE); break;
        case ',' : add_token(TokenType::COMMA); break;
        case '.' : add_token(TokenType::DOT); break;
        case '-' : add_token(TokenType::MINUS); break;
        case '+' : add_token(TokenType::PLUS); break;
        case ';' : add_token(TokenType::SEMICOLON); break;
        case '*' : add_token(TokenType::STAR); break;

        case '!':
            add_token(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
            break;
        case '=':
            add_token(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;
        case '<':
            add_token(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
            break;
        case '>':
            add_token(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
            break;

        case '/':
            if (match('/')) {
                // A comment goes until the end of the line.
                while (peek() != '\n' && !is_at_end()) advance();
            } else {
                add_token(TokenType::SLASH);
            }
        break; 
        default:
            Lox::error(line, "Unexpected character."); //cases like @#^
            break;
    }
}

char Scanner::advance() {
    return source[current++];
}

void Scanner::add_token(TokenType type) {
    add_token(type, nullptr);
}

void Scanner::add_token(TokenType type, void* literal) {
    std::string text = source.substr(start, current);
    tokens.push_back(Token{type, text, literal, line});
}

bool Scanner::match(char expected) {
    if(is_at_end()) return false;
    if(source[current] != expected) return false;

    current++;
    return true;
}

char Scanner::peek() {
    if(is_at_end()) return '\0';
    return source[current];
}

