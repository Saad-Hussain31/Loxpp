#include <iostream>
#include <string>
#include <vector>
#include "Token.hpp"
#include "TokenType.hpp"

namespace lox::interpreter {
using std::string;

class Scanner {
    public:
        Scanner() = default;
        Scanner(string source);
        std::vector<Token> scan_tokens();

    private:
        bool is_at_end();
        
    private:
        string source;
        std::vector<Token> tokens;
        int start = 0;
        int current = 0;
        int line = 1;
};
} // end lox::interpreter