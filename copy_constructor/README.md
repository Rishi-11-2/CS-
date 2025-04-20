# Copy Constructor Examples

This folder contains C++ examples demonstrating the use of copy constructors, particularly focusing on deep copy semantics when dealing with dynamic memory.

## Files
- **deep_copy.cpp:** Shows how to implement a custom copy constructor to perform a deep copy of dynamically allocated memory within a class. The example highlights the importance of deep copying to avoid issues like double deletion and unintended sharing of resources.

## Key Concepts
- Copy constructor syntax and usage
- Shallow copy vs. deep copy
- Memory management in C++ classes

## How to Build & Run
```sh
g++ -std=c++11 deep_copy.cpp -o deep_copy
./deep_copy
```

---
