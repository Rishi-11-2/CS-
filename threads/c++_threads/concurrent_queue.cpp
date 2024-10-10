#include <bits/stdc++.h>
using namespace std;

struct Concurrent_Queue {
    queue<int> q;
    mutex mtx;
    condition_variable cv;
    bool ops = false;

    void enqueue(int a) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return !ops; });

        ops = true;
        q.push(a);

        ops = false;
        cv.notify_all();  
    }

    int sz() {
        lock_guard<mutex> lock(mtx);  
        return (int)q.size();
    }
};

int main() {
    Concurrent_Queue cq;
    vector<thread> v;

    for (int i = 1; i <= (int)(1e4); i++) {
        v.push_back(thread([&cq, i] { cq.enqueue(i); }));  
    }

    for (auto &it : v) {
        it.join();
    }

    cout << cq.sz() << endl;

    return 0;
}
