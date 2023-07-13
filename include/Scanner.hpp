#include <iostream>
#include <string>
#include <vector>
#include "Token.hpp"
#include "TokenType.hpp"

namespace lox::interpreter {
using std::string;

class Scanner {
    public:
        Scanner(string source) : 
        source(source) {}

    private:
        string source;
        std::vector<Token> tokens;
};
} // end lox::interpreter