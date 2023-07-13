cmake_minimum_required(VERSION 3.20)
project(Loxpp)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(Headers
    include/Lox.hpp
    include/TokenType.hpp 
    include/Token.hpp   
    include/Scanner.hpp
)

set(Sources
    src/lox/Lox.cpp
    src/lox/Scanner.cpp
)

add_executable(loxpp ${Sources} ${Headers})
target_compile_options(loxpp PUBLIC -Wzero-as-null-pointer-constant)




