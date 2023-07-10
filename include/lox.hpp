#pragma once
#include <string>


namespace lox::interpreter {
    
class Lox {
    private:
        static void run_file(const std::string& path);
        static void run_prompt();
        static void run(const std::string& source);
        static void error(int line, const std::string& message);
        static void report(int line, const std::string& where, const std::string& message);
        static bool had_error;
    public:
        void init(int argc, char** argv);
};
bool Lox::had_error = false;
    
}



