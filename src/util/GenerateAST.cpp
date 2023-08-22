#include "util/GenerateAST.hpp"


#include "lox/Token.hpp"
#include <vector>
#include <any>

using namespace util::interpreter;

void GenerateAST::init(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: generate_ast <output directory>\n";
        exit(0);
    }
    std::string output_dir = argv[1];
    define_ast(output_dir, "Expr", {
        "Binary   : Expr* left, Token* operatorToken, Expr* right",
        "Grouping : Expr* expression",
        "Literal  : std::any value",
        "Unary    : Token* operatorToken, Expr* right"
        "Assign   : Token* name, Expr* value"
        "Call     : Expr* callee, Token* paren, std::vector<std::string> args"
    });
}


void GenerateAST::define_ast(const std::string& output_dir, const std::string& base_name, const std::vector<std::string>& types) {
    std::string path = output_dir + "/" + base_name + ".cpp";
    std::ofstream writer(path);

    writer << "#include \"" << base_name << ".hpp\"\n";
    writer << "#include <vector>\n";
    writer << "#include <any>\n"; // Fix the include directive

    writer << "namespace lox::interpreter {\n";
    writer << "\n";

    // Define the visitor interface
    writer << "template <typename R>\n";
    writer << "class " << base_name << "Visitor {\n";
    writer << "public:\n";
    for (const std::string& type : types) {
        std::string class_name = type.substr(0, type.find(":"));
        writer << "    virtual R visit" << class_name << "(" << class_name << "&) = 0;\n";
    }
    writer << "};\n";
    writer << "\n";

    // Define the base class
    writer << "class " << base_name << " {\n";
    writer << "public:\n";
    writer << "    virtual ~" << base_name << "() {}\n";
    writer << "    template <typename R>\n";
    writer << "    virtual R accept(" << base_name << "Visitor<R>& visitor) = 0;\n";
    writer << "};\n";
    writer << "\n";

    for (const std::string& type : types) {
        std::string class_name = type.substr(0, type.find(":"));
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

    // accept() method
    writer << "\n";
    writer << "    <R> R accept(Visitor<R>& visitor) override {\n";
    writer << "        return visitor.visit" << class_name << "(*this);\n";
    writer << "    }\n";

    writer << "};\n";
    writer << "\n";
}


int main(int argc, char* argv[]) {
    GenerateAST ast;
    ast.init(argc, argv);
    return 0;
}