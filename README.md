
# Loxpp Interpreter

The Loxpp interpreter is an implementation of the Lox programming language. Lox is a dynamically-typed, interpreted language designed for educational purposes and is described in the book "Crafting Interpreters" by Bob Nystrom.

## Features

- Ability to run Lox code from a file or interactively from the command line.
- Lexical analysis (scanning) of Lox source code to generate tokens.
- Error reporting with line numbers.
- Basic token types, including single-character tokens, literals (identifiers, strings, numbers), and keywords.

## Usage

1. Clone the repository and navigate to the project directory.
```
git clone git@github.com:Saad-Hussain31/Loxpp.git
```

2. Build the interpreter:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make

```

3. Run the Loxpp interpreter:

- Run a Lox script file:

```
$ ./loxpp path/to/script.lox
```
- Start an interactive Lox prompt:
  ```
  $ ./loxpp
  ```

4. Enter Lox code in the file or prompt and observe the output.

## Code Structure
- `Lox.hpp` and `Lox.cpp`: Contains the Lox class for running Lox code, error handling, and initialization.
- `Scanner.hpp` and `Scanner.cpp`: Defines the Scanner class responsible for lexical analysis (scanning) of Lox source code.
- `Token.hpp` and `Token.cpp`: Defines the Token class representing a token in Lox.
- `TokenType.hpp`: Declares the TokenType enum class representing token types.


## Dependencies

- C++17 compatible compiler
- CMake (version 3.10 or higher)


## Contributions

Contributions are welcome! Feel free to open an issue or submit a pull request.

## Acknowledgments

The Loxpp interpreter is based on the Lox programming language described in the book "Crafting Interpreters" by Bob Nystrom.