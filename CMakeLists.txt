cmake_minimum_required(VERSION 3.20)
project(Loxpp)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(Headers
    include/lox/Lox.hpp
    include/lox/TokenType.hpp 
    include/lox/Token.hpp   
    include/lox/Scanner.hpp
)

set(Sources
    src/lox/Lox.cpp
    src/lox/Scanner.cpp
)

add_executable(generate-ast src/util/GenerateAST.cpp include/util/GenerateAST.hpp)

add_executable(loxpp ${Sources} ${Headers})
target_compile_options(loxpp PUBLIC -Wzero-as-null-pointer-constant)




