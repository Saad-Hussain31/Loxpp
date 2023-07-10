#pragma once
#include <string>

namespace lox::interpreter {
class Lox {
    public:
        static void run_file(const std::string& path);
        static void run_prompt();
        static void run(const std::string& source);
};
}



