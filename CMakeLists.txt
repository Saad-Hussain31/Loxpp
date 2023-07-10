cmake_minimum_required(VERSION 3.20)
project(Loxpp)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(Headers    
)

set(Sources
    src/lox/lox.cpp
)

add_executable(loxpp ${Sources} ${Headers})






