#include<bits/stdc++.h>
using namespace std;

enum track {A,B,C};

class Instr{
    public:
    void play(track t)
    {
        cout<<"Instr:: play"<<endl;
    }
};

class Guitar:public Instr{

    public:
    void play(track t)
    {
        cout<<"Guitar:: play"<<endl;
    }
};

void callerTune(Instr *p,track r)
{
    p->play(r);
}
void guitarTune(Guitar *g,track r)
{
    g->play(r);
}

int main()
{
    Guitar g;
    Instr s;

    s.play(A);
    g.play(B);

    callerTune(&s,A);
    callerTune(&g,A);
    // guitarTune(&s,A); // downcasting not possible in c++
    guitarTune(&g,A);

}