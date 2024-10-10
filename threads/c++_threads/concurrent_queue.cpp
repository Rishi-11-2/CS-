#include <bits/stdc++.h>
using namespace std;

struct Concurrent_Queue {
    queue<int> q;
    mutex mtx;
    condition_variable cv;
    bool ops = false;

    void enqueue(int a) {
        unique_lock<mutex> lock(mtx);
        // Wait until no other operation is being performed
        cv.wait(lock, [this] { return !ops; });

        // Critical section (modify queue)
        ops = true;
        q.push(a);

        // End operation and notify other threads
        ops = false;
        cv.notify_all();  // Notify waiting threads that enqueue has finished
    }

    int sz() {
        lock_guard<mutex> lock(mtx);  // Lock while reading size
        return (int)q.size();
    }
};

int main() {
    Concurrent_Queue cq;
    vector<thread> v;

    // Create a large number of threads
    for (int i = 1; i <= (int)(1e4); i++) {
        v.push_back(thread([&cq, i] { cq.enqueue(i); }));  // Lambda to pass the object and argument
    }

    // Join all threads
    for (auto &it : v) {
        it.join();
    }

    // Output the size of the queue
    cout << cq.sz() << endl;

    return 0;
}
