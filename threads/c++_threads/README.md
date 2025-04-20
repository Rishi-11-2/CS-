# Concurrent Threads in C++

This directory contains C++ programs that demonstrate the use of threads, mutexes, and condition variables to solve classic concurrency problems. The focus is on safe and efficient communication and synchronization between threads.

## concurrent_queue.cpp

This program implements a **thread-safe concurrent queue** using C++ standard library features:
- **`std::mutex`** and **`std::condition_variable`** are used to ensure thread-safe access and coordination between multiple threads.
- The `Concurrent_Queue` struct provides:
  - `enqueue(int)`: Thread-safe method to add elements to the queue.
  - `dequeue()`: Thread-safe method to remove elements from the queue, blocking if the queue is empty.
- The main function demonstrates concurrent enqueue and dequeue operations using multiple threads, showing how producers and consumers interact safely.

**Key Concepts Illustrated:**
- Mutual exclusion with mutexes
- Condition variables for signaling between threads
- Producer-consumer synchronization
- Safe access to shared data structures

## Other Files
- **producer_consumer.cpp**: Demonstrates the classic producer-consumer problem using threads and synchronization primitives.
- **reader_writer.cpp**: Shows the implementation of the reader-writer problem, balancing concurrent read access with exclusive write access.

## How to Build & Run
1. **Compile:**
   ```sh
   g++ -std=c++11 -pthread concurrent_queue.cpp -o concurrent_queue
   ```
2. **Run:**
   ```sh
   ./concurrent_queue
   ```

> **Note:** Ensure you have a C++11 (or newer) compliant compiler and use the `-pthread` flag for thread support.

---

