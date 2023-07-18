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
        if(std::isdigit(c)) {
            number();
        } else if (std::isalpha(c)) {
            identifier();
        }else {
            Lox::error(line, "Unexpected character."); //cases like @#^
        }
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
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(Token{type, text, literal, line});
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

    std::string value = source.substr(start + 1, current - start - 2);
    add_token(TokenType::STRING, value);  
}


void Scanner::number() {
    
    while(std::isdigit(peek())) 
        advance();

    if(peek() == '.' && std::isdigit(peek_next())) {
        while(std::isdigit(peek())) 
            advance();
    }

    add_token(TokenType::NUMBER, std::stod(source.substr(start, current - start)));

}

char Scanner::peek_next() {
    if(current + 1 >= source.size())
        return '\0';
    return source[current+1]; 
}

void Scanner::identifier() {
    while(std::isalnum(peek()))
        advance();

    std::string text = source.substr(start, current - start);
    TokenType type = TokenType::IDENTIFIER;

    auto it = keywords.find(text);
    if (it != keywords.end()) {
        type = it->second;
    }

    add_token(type);

}

std::map<std::string, TokenType> Scanner::keywords = {
    {"and",    TokenType::AND},
    {"class",  TokenType::CLASS},
    {"else",   TokenType::ELSE},
    {"false",  TokenType::FALSE},
    {"for",    TokenType::FOR},
    {"fun",    TokenType::FUN},
    {"if",     TokenType::IF},
    {"nil",    TokenType::NIL},
    {"or",     TokenType::OR},
    {"print",  TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super",  TokenType::SUPER},
    {"this",   TokenType::THIS},
    {"true",   TokenType::TRUE},
    {"var",    TokenType::VAR},
    {"while",  TokenType::WHILE}
};

