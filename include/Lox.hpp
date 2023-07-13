#pragma once
#include <string>

namespace lox::interpreter {
using std::string;

class Lox {
    private:
        static void run_file(const std::string& path);
        static void run_prompt();
        static void run(const std::string& source);
        static void error(int line, const std::string& message);
        static void report(int line, const std::string& where, const std::string& message);
        inline static bool had_error = false;
    public:
        void init(int argc, char** argv);
};
    
}



