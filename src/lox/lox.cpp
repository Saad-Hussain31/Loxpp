
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "lox.hpp"

using namespace lox::interpreter;

namespace {
    struct Token {
        std::string lexeme;
    };

    std::vector<Token> scan_tokens(const std::string& source) {
        std::vector<Token> tokens;
        std::istringstream iss(source);

        std::string token;
        while (iss >> token) {
            tokens.push_back(Token{ token });
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
    if(had_error)
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
    had_error = false;
}

void Lox::error(int line, string message) {
    report(line, "", message);
}

void Lox::report(int line, string where, string message) {
    std::cerr << "[line " << line << "] Error" << where << ": " << message << std::endl;
    had_error = true;
}

int main(int argc, char** argv) {
    Lox lox;
    if(argc > 2) {
        std::cout << ("Usage: loxpp [script]");
    } else if(argc == 2) {
        lox.run_file(argv[1]);
    } else {
        lox.run_prompt();
    }
}




