# C++ Concepts and Patterns – Code Collection

This repository contains a comprehensive set of C++ code examples, each demonstrating core concepts, language features, and common patterns in modern C++. The structure is organized by topic, with each folder containing focused examples and explanations.

## Directory Overview
- **big_endian_to_little_endian.cpp / checking_endian.cpp**: Byte order, endianness, and memory representation.
- **conversion_operator.cpp**: User-defined type conversion operators.
- **copy_constructor/**: Deep copy and copy constructor usage.
- **diamond_problem/**: Multiple inheritance, diamond problem, and virtual inheritance.
- **function_binding/**: Function pointers, static/dynamic binding, and virtual functions.
- **object_slicing/**: Object slicing and virtual destructors.
- **pure_virtual_functions/**: Pure virtual functions and abstract classes.
- **threads/**: Threading, mutexes, condition variables, and classic concurrency problems.
- **virtual_table/**: Virtual table (vtable), dynamic dispatch, and polymorphism.

## How to Build & Run
All examples are written in standard C++11 or newer. To compile and run an example:

```sh
# Example for a single file
# (replace <file>.cpp with the desired file)
g++ -std=c++11 <file>.cpp -o <file_name>
./<file_name>

# Example for a folder
cd <folder>
g++ -std=c++11 <main_file>.cpp -o <main_file>
./<main_file>
```

> **Note:** Use the `-pthread` flag for examples involving threads.

## License
This repository is provided for educational purposes. See the `LICENSE` file for details.

---
