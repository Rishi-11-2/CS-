/*
Overview:
This C++ program demonstrates function overriding and function binding in inheritance without the use of virtual functions. The `Instr` base class and `Guitar` derived class both define a `play` method. The program shows how static binding works, and how function calls are resolved at compile time, even when using base class pointers to derived objects.
*/
#include<bits/stdc++.h>
/*
Include the standard C++ library header for commonly used functions and objects
*/
using namespace std;

/* Define an enumeration for track options */
enum track {A,B,C};

/* Base class representing an instrument */
class Instr{
    public:
    /* Method to play the instrument */
    void play(track t)
    {
        /* Output a message indicating the instrument is playing */
        cout<<"Instr:: play"<<endl;
    }
};

/* Derived class representing a guitar, inheriting from Instr */
class Guitar:public Instr{

    public:
    /* Method to play the guitar (overrides Instr::play) */
    void play(track t)
    {
        /* Output a message indicating the guitar is playing */
        cout<<"Guitar:: play"<<endl;
    }
};

/* Function to play a tune using an Instr object */
void callerTune(Instr *p,track r)
{
    /* Calls Instr::play regardless of the actual object type (static binding) */
    p->play(r);
}

/* Function to play a tune using a Guitar object */
void guitarTune(Guitar *g,track r)
{
    /* Calls Guitar::play (static binding) */
    g->play(r);
}

int main()
{
    /* Create a Guitar object */
    Guitar g;
    /* Create an Instr object */
    Instr s;

    /* Play the Instr object */
    s.play(A); /* Calls Instr::play */
    /* Play the Guitar object */
    g.play(B); /* Calls Guitar::play */

    /* Play a tune using the Instr object */
    callerTune(&s,A); /* Calls Instr::play */
    /* Play a tune using the Guitar object (static binding, no virtual) */
    callerTune(&g,A); /* Calls Instr::play due to static binding (no virtual) */
    /* guitarTune(&s,A); // downcasting not possible in c++ */
    /* Play a tune using the Guitar object */
    guitarTune(&g,A); /* Calls Guitar::play */

}