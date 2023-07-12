
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#include "Lox.hpp"
#include "Token.hpp"

using namespace lox::interpreter;

namespace {

//TODO: This needs to be removed and moved to Scanner class.
    std::vector<Token> scan_tokens(const std::string& source) {
        std::vector<Token> tokens;
        std::istringstream iss(source);

        std::string token;
        while (iss >> token) {
            // tokens.push_back(Token{ token });
            tokens.push_back(Token{ TokenType::UNKNOWN, token, nullptr, 0 });
        }

        return tokens;
    }
}

void Lox::run(const std::string& source) {
    std::vector<Token> tokens = scan_tokens(source);
    for(const Token& token : tokens) {
        std::cout << token.lexeme << "\n";
    }
}



void Lox::run_file(const std::string& path) {
  if (path.empty()) {
    throw std::invalid_argument("Invalid file path.");
  }

  std::ifstream file(path, std::ios::binary);

  if (file) {
    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    run(content);
    if(Lox::had_error)
        exit(EXIT_FAILURE);
  } else {
    throw std::runtime_error("Failed to open file: " + path);
  }
}


void Lox::run_prompt() {
    std::string line;
    for(;;) {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line.empty()) break;
    }
    run(line);
    Lox::had_error = false;
}

void Lox::error(int line, const std::string& message) {
    report(line, "", message);
}

void Lox::report(int line, const std::string& where, const std::string& message) {
    std::cerr << "[line " << line << "] Error" << where << ": " << message << std::endl;
    Lox::had_error = true;
}

void Lox::init(int argc, char* argv[]) {
    if(argc > 2) {
        std::cout << ("Usage: loxpp [script]");
    } else if(argc == 2) {
        run_file(argv[1]);
    } else {
        run_prompt();
    }
}

int main(int argc, char* argv[]) {
   Lox lox;
   lox.init(argc,  argv);
   return 0;
}




