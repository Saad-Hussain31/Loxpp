#include "Lox.hpp"
#include "Scanner.hpp"


using namespace lox::interpreter;

Scanner::Scanner(std::string source) : source(source) {}

std::vector<Token> Scanner::scan_tokens() {
    while(!is_at_end()) {
        //at the beginning of next lexeme
        start = current;
        scan_tokens(false);
    }
    tokens.emplace_back(Token{TokenType::END_OF_FILE, "", nullptr, line});
    return tokens;
}

bool Scanner::is_at_end() {
    return current > source.size();
}

void Scanner::scan_tokens(bool flag) {
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
                while (peek() != '\n' && !is_at_end()) 
                    advance();
            } else {
                add_token(TokenType::SLASH);
            }
        break; 

        case ' ':
        case '\r':
        case '\t':
            // Ignore whitespace.
            break;
        case '\n':
            line++;
            break;
        case '"': string(); break;

        default:
        if(is_digit(c)) 
            number();
        else 
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

void Scanner::add_token(TokenType type, std::any literal) {
    std::string text = source.substr(start, current);
    tokens.emplace_back(type, text, literal, line);
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

void Scanner::string() {

    while(peek() != '"' && !is_at_end()) {
        if(peek() == '\n') line++;
        advance();
    } 

    
    if(is_at_end()) {
        Lox::error(line, "Unterminated String.");
    }
    
    advance();

    std::string value = source.substr(start + 1, current - 1);
    add_token(TokenType::STRING, value); //TODO(Saad): Look out for void ptr casting to string  
}

bool Scanner::is_digit(char c) {
    return c >= '0' && c <= '9'; 
}

void Scanner::number() {
    
    while(is_digit(peek())) 
        advance();

    if(peek() == '.' && is_digit(peek_next())) {
        while(is_digit(peek())) 
            advance();
    }

    add_token(TokenType::NUMBER, std::stod(source.substr(start, current)));

}

char Scanner::peek_next() {
    if(current + 1 >= source.size())
        return '\0';
    return source[current+1]; 
}
