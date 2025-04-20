/*
Overview:
This C++ program implements a thread-safe concurrent queue using mutexes and condition variables from the C++ standard library. The `Concurrent_Queue` struct provides thread-safe enqueue and dequeue operations, ensuring correct synchronization between producer and consumer threads. The main function demonstrates concurrent enqueueing and dequeueing using multiple threads, and prints the queue size and dequeued values.
*/

#include <bits/stdc++.h>
// Include the standard C++ library header for commonly used functions and objects
using namespace std;

struct Concurrent_Queue {
    queue<int> q; // Standard queue to store integer elements
    mutex mtx; // Mutex to synchronize access
    condition_variable cv; // Condition variable for notification
    bool ops = false; // Flag to indicate if an operation is in progress

    /**
     * Enqueue an element into the concurrent queue.
     * 
     * This function acquires a lock, waits until no operation is in progress,
     * adds the element to the queue, and notifies all waiting threads.
     * 
     * @param a The element to be enqueued.
     */
    void enqueue(int a) {
        unique_lock<mutex> lock(mtx); // Acquire lock for thread safety
        cv.wait(lock, [this] { return !ops; }); // Wait until no operation is in progress

        ops = true; // Mark operation in progress
        q.push(a); // Add element to the queue

        ops = false; // Mark operation as finished
        cv.notify_all();  // Notify all waiting threads
    }

    /**
     * Dequeue an element from the concurrent queue.
     * 
     * This function acquires a lock, waits until no operation is in progress,
     * removes the front element from the queue, and notifies one waiting thread.
     * 
     * @return The dequeued element, or -1 if the queue is empty.
     */
    int dequeue()
    {
        if(sz()==0)
            return -1; // Return -1 if queue is empty
        unique_lock<mutex>lock(mtx); // Acquire lock for thread safety
        cv.wait(lock,[this]{
            return !ops;
        }); // Wait until no operation is in progress

        ops=true; // Mark operation in progress
        int c=q.front(); // Get the front element
        q.pop(); // Remove the front element

        ops=false; // Mark operation as finished
        cv.notify_one(); // Notify one waiting thread
        return c;

    }

    /**
     * Get the size of the concurrent queue.
     * 
     * This function acquires a lock and returns the size of the queue.
     * 
     * @return The size of the queue.
     */
    int sz() {
        lock_guard<mutex> lock(mtx);  // Acquire lock to get size
        return (int)q.size();
    }
};

int main() {
    Concurrent_Queue cq; // Create a concurrent queue
    vector<thread> v;

    // Launch multiple threads to enqueue values
    for (int i = 1; i <= (int)(1e2); i++) {
        v.push_back(thread([&cq, i] { 
            cq.enqueue(i); 
            }
        ));  
    }

    for (auto &it : v) {
        it.join(); // Wait for all enqueue threads to finish
    }

    cout << cq.sz() << endl; // Print queue size after enqueueing
    vector<thread>vv;
    // Launch multiple threads to dequeue values
    for(int i=1;i<=(int)(1e2)+1;i++)
    {
        vv.push_back(thread([&cq]{
            int cc=cq.dequeue();

            cout<<cc<<endl;
          }
        ));
    }
    for(auto &it:vv)
    {
        it.join(); // Wait for all dequeue threads to finish
    }
    cout << cq.sz() << endl; // Print queue size after dequeueing
    return 0;
}
