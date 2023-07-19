#ifndef LOX_H
#define LOX_H
#include <string>

namespace lox::interpreter {
using std::string;

class Lox {
    public:
        void init(int argc, char** argv);
        static void error(int line, const std::string& message);

    private:
        static void run_file(const std::string& path);
        static void run_prompt();
        static void run(const std::string& source);
        static void report(int line, const std::string& where, const std::string& message);
        
    private:
        inline static bool had_error = false;

};
    
} // end lox::interpreter

#endif // LOX_H

