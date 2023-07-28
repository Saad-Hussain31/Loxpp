/**
 * @file GenerateAST.cpp
 * @brief Implements the GenerateAST tool for the Loxpp project.
 *
 * This file is part of Loxpp, a Lox language compiler project.
 *
 * @author Saad Hussain
 * @date 28-07-2023
 */

#include "util/GenerateAST.hpp"

using namespace util::interpreter;

void GenerateAST::init(int argc, char* argv[]) {
    if(argc < 2 ) {
        std::cout << "Usage: generate_ast <output directory>\n";
    }
    std::string output_dir = argv[1];
}