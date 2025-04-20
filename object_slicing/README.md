# Object Slicing and Virtual Destructors

This folder contains C++ examples demonstrating object slicing and the importance of virtual destructors in inheritance.

## Files
- **object_slicing.cpp:** Shows what happens when a derived class object is assigned to a base class object, resulting in object slicing.
- **virtual_desctructor.cpp:** Demonstrates the use of virtual destructors to ensure proper cleanup in polymorphic base classes.

## Key Concepts
- Object slicing
- Base vs. derived class assignment
- Virtual destructors
- Memory management in inheritance

## How to Build & Run
```sh
g++ -std=c++11 object_slicing.cpp -o object_slicing
./object_slicing
```

---
