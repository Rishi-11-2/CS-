#include<bits/stdc++.h>
using namespace std;
mutex mtx;
condition_variable cv;
int readers=0;

bool writes=false;


void start_read()
{
    unique_lock<mutex>lock(mtx);
    cv.wait(lock,[]{return (!writes && readers<2) ; });

    readers++;
}

void end_read()
{
    lock_guard<mutex>lock(mtx);
    readers--;
    if(readers==0)
    {
        cv.notify_one();
    }
}
void start_write()
{
    unique_lock<mutex>lock(mtx);

    cv.wait(lock,[]{return (!writes && readers==0 ) ;});

    writes=true;
}
void end_write()
{
    lock_guard<mutex>lock(mtx);
    writes=false;
    cv.notify_all();
}
void reader(int idx)
{
    start_read();
    cout<<"Reader: "<<idx<<" has Started Reading"<<endl;

    this_thread::sleep_for(chrono::milliseconds(100));

    cout<<"Reader: "<<idx<<"has Stopped Reading"<<endl;

    end_read();
}
void writer(int idx)
{
    start_write();

    cout<<"Writer: "<<idx<<"has Started Writting"<<endl;

    this_thread::sleep_for(chrono::milliseconds(100));

    cout<<"Writer: "<<idx<<"has Stopped Writting"<<endl;

    end_write();

}
int main()
{
    vector<thread>readers_vec;
    vector<thread>writers_vec;

    cout<<"Enter the number of readers -->";
    int rc;
    cin>>rc;

    cout<<endl;

    cout<<"Enter the number of writers -->";

    int wc;
    cin>>wc;

    cout<<endl;

    for(int i=1;i<=rc;i++)
    {
        thread t(reader,i);
        readers_vec.push_back(move(t));
    }
    for(int i=1;i<=wc;i++)
    {
        thread t(writer,i);
        writers_vec.push_back(move(t));
    }

    for(auto &it:readers_vec)
    {
        it.join();
    }
    for(auto &it:writers_vec)
    {
        it.join();
    }

}