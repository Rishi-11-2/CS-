#include<bits/stdc++.h>
using namespace std;

queue<int>buffer;
mutex mtx;
condition_variable cv;
void producer()
{
    {
        lock_guard<mutex> lock(mtx);
        buffer.push(42);
        buffer.push(41);
        // cout<<"Hi"<<endl;
    }
    // cv.notify_one(); // not needed because of the predicate in cv.wait
}

void consumer()
{
    int data;
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[]{return !buffer.empty();}); // (wait expects unique_lock and a predicate in argument)
        data=buffer.front();
        buffer.pop();
        cout<<data<<endl;
    }
}
int main()
{
    thread producerThread(producer);
    thread consumerThread(consumer);
    thread consumerThread2(consumer);

    producerThread.join();
    consumerThread.join();
    consumerThread2.join();

    return 0;
}