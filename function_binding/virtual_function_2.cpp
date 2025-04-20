/*
Overview:
This C++ program demonstrates dynamic binding using virtual functions in an inheritance hierarchy. 
The `Instr` base class declares a virtual `play` method, which is overridden in the `Guitar` derived class. 
The program shows how function calls through base class pointers are resolved at runtime, allowing for polymorphic behavior.
*/
#include<bits/stdc++.h>
/*
Include the standard C++ library header for commonly used functions and objects
*/
using namespace std;

/* Define an enumeration for track types */
enum track {A,B,C};

/* Base class Instr with a virtual play method */
class Instr{
    public:
    /* Virtual method to be overridden by derived classes */
    virtual void play(track t)
    {
        /* Default implementation in the base class */
        cout<<"Instr:: play"<<endl;
    }
};

/* Derived class Guitar that inherits from Instr */
class Guitar:public Instr{

    public:
    /* Override the play method to provide a specific implementation for Guitar */
    void play(track t)
    {
        /* Implementation specific to Guitar */
        cout<<"Guitar:: play"<<endl;
    }
};

/* Function that takes a base class pointer and a track type as arguments */
void callerTune(Instr *p,track r)
{
    /* Dynamic binding: calls the appropriate play method based on the actual object type */
    p->play(r); /* dynamic binding i.e. binding done in runtime */
    /* Instr::play or Guitar::Play printed depends on the object type pointed */
}

/* Function that takes a Guitar pointer and a track type as arguments */
void guitarTune(Guitar *g,track r)
{
    /* Static binding: calls Guitar::play */
    g->play(r);  /* static binding , binding done in compile time */
}

int main()
{
    /* Create objects of type Guitar and Instr */
    Guitar g;
    Instr s;

    /* Call the play method on the Instr object */
    s.play(A); /* Calls Instr::play */

    /* Call the play method on the Guitar object */
    g.play(B); /* Calls Guitar::play */

    /* Call the callerTune function with an Instr pointer and a track type */
    callerTune(&s,A); /* Calls Instr::play */

    /* Call the callerTune function with a Guitar pointer and a track type */
    callerTune(&g,A); /* Calls Guitar::play due to dynamic binding (virtual) */

    /* Attempting to downcast an Instr pointer to a Guitar pointer is not allowed in C++ */
    // guitarTune(&s,A); // downcasting not possible in c++

    /* Call the guitarTune function with a Guitar pointer and a track type */
    guitarTune(&g,A); /* Calls Guitar::play */

}