/**
 * @file Lox.hpp
 * @brief Header file for the Lox interpreter.
 */

#ifndef LOX_H
#define LOX_H

#include <string>

namespace lox::interpreter {
using std::string;

/**
 * @class Lox
 * @brief The main class for the Lox interpreter.
 */
class Lox {
public:
    /**
     * @brief Initialize the Lox interpreter.
     * @param argc The number of command-line arguments.
     * @param argv An array of C-style strings containing the command-line arguments.
     */
    void init(int argc, char** argv);

    /**
     * @brief Report an error with a given line number and error message.
     * @param line The line number where the error occurred.
     * @param message The error message.
     */
    static void error(int line, const std::string& message);

private:
    /**
     * @brief Run the Lox interpreter on a source file.
     * @param path The file path of the source file to run.
     */
    static void run_file(const std::string& path);

    /**
     * @brief Run the Lox interpreter in interactive mode (REPL).
     */
    static void run_prompt();

    /**
     * @brief Run the Lox interpreter on a given source code.
     * @param source The source code to run.
     */
    static void run(const std::string& source);

    /**
     * @brief Report a runtime error with a given line number, location, and error message.
     * @param line The line number where the error occurred.
     * @param where The location of the error.
     * @param message The error message.
     */
    static void report(int line, const std::string& where, const std::string& message);

private:
    inline static bool had_error = false; ///< Tracks if there was an error during interpretation.
};

} // end lox::interpreter

#endif // LOX_H
