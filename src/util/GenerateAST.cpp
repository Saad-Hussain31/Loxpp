/**
 * @file GenerateAST.cpp
 * @brief Implements the GenerateAST tool for the Loxpp project.
 *
 * This file is part of Loxpp, a Lox language compiler project.
 *
 * @author Saad Hussain
 * @date 28-07-2023
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "util/GenerateAST.hpp"

using namespace util::interpreter; 

void GenerateAST::init(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: generate_ast <output directory>\n";
        exit(64);
    }
    std::string output_dir = argv[1];
    define_ast(output_dir, "Expr", {
        "Binary   : Expr* left, Token* operator, Expr* right",
        "Grouping : Expr* expression",
        "Literal  : std::any value",
        "Unary    : Token* operator, Expr* right"
    });
}


void GenerateAST::define_ast(const std::string& output_dir, const std::string& base_name, const std::vector<std::string>& types) {
        std::string path = output_dir + "/" + base_name + ".cpp";
        std::ofstream writer(path);

        writer << "#include \"" << base_name << ".hpp\"\n";
        writer << "#include <vector>\n";
        writer << "#include <std::any>\n";
        writer << "namespace lox::interpreter {\n";
        writer << "\n";

        // Abstract base class
        writer << "class " << base_name << " {\n";
        writer << "public:\n";
        writer << "    virtual ~" << base_name << "() {}\n";
        writer << "};\n";
        writer << "\n";

        for (const std::string& type : types) {
            std::string class_name = type.substr(0, type.find(":")); // Remove leading/trailing spaces
            class_name.erase(0, class_name.find_first_not_of(" \t\n\r\f\v"));
            class_name.erase(class_name.find_last_not_of(" \t\n\r\f\v") + 1);

            std::string fields = type.substr(type.find(":") + 1);

            define_type(writer, base_name, class_name, fields);
        }

        writer << "}\n";
        writer.close();
}

void GenerateAST::define_type(std::ofstream& writer, const std::string& base_name, const std::string& class_name,
const std::string& field_list) {
        writer << "class " << class_name << " : public " << base_name << " {\n";
        writer << "public:\n";

        // Constructor.
        writer << "    " << class_name << "(" << field_list << ") : ";
        std::stringstream ss(field_list);
        std::string field;
        while (std::getline(ss, field, ',')) {
            std::string name = field.substr(field.find(" ") + 1); // Remove leading/trailing spaces
            name.erase(0, name.find_first_not_of(" \t\n\r\f\v"));
            name.erase(name.find_last_not_of(" \t\n\r\f\v") + 1);

            writer << name << "(" << name << ")";
            if (!ss.eof()) {
                writer << ", ";
            }
        }
        writer << " {}\n";

        // Fields.
        writer << "\n";
        ss.clear();
        ss.str(field_list);
        while (std::getline(ss, field, ',')) {
            writer << "    " << field << ";\n";
        }

        writer << "};\n";
        writer << "\n";
}



int main(int argc, char* argv[]) {
    GenerateAST ast;
    ast.init(argc, argv);
    return 0;
}
