#pragma once
#include <string>


namespace lox::interpreter {
    using string = const std::string&;
class Lox {
    public:
        static void run_file(const std::string& path);
        static void run_prompt();
        static void run(const std::string& source);
        static void error(int line, const std::string& message);
        static void report(int line, string where, string message);

};
    static bool had_error = false;
}



