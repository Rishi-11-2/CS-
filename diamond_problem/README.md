# Diamond Problem and Virtual Inheritance

This folder contains C++ examples illustrating the diamond problem in multiple inheritance and how virtual inheritance resolves ambiguity.

## Files
- **virtual_inheritance.cpp:** Demonstrates a class hierarchy where two derived classes inherit from a common base class, and a further derived class inherits from both. The example shows how virtual inheritance ensures only one instance of the base class is present in the most-derived class, preventing ambiguity.

## Key Concepts
- Multiple inheritance
- Diamond problem
- Virtual inheritance
- Constructor and destructor order

## How to Build & Run
```sh
g++ -std=c++11 virtual_inheritance.cpp -o virtual_inheritance
./virtual_inheritance
```

---
