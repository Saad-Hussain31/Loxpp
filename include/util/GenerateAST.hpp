/**
 * @file GenerateAST.hpp
 * @brief Header file for the GenerateAST utility class for Lox interpreter.
 */

#ifndef GENERATE_AST_HPP
#define GENERATE_AST_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace util::interpreter {

/**
 * @brief Utility class for generating AST expressions in C++.
 */
class GenerateAST {
public:
    /**
     * @brief Main entry point to generate AST classes.
     * @param argc The number of command-line arguments.
     * @param argv An array of command-line arguments.
     */
    void init(int argc, char* argv[]);

public:
    /**
     * @brief Defines the AST classes and generates the .cpp file.
     * @param output_dir The output directory for the generated files.
     * @param base_name The base name for the AST classes.
     * @param types A vector of strings defining each AST class and its fields.
     */
    void define_ast(const std::string& output_dir, const std::string& base_name, const std::vector<std::string>& types);

    /**
     * @brief Defines a specific AST class and writes it to the output file.
     * @param writer The output file stream.
     * @param base_name The base name for the AST classes.
     * @param class_name The name of the current AST class being defined.
     * @param field_list The list of fields for the current AST class.
     */
    void define_type(std::ofstream& writer, const std::string& base_name, const std::string& class_name, const std::string& field_list);
};

} //end util::interpreter

#endif // GENERATE_AST_HPP
