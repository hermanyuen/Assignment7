#include "Probe.h"

#include <ostream>

//Define a probe(class Probe) that can be inserted into a class (class Target) as a test coverage device. 
// (Note : the data and function members of the probe cannot be static. The probe itself must be declared static in the Target class.)  
// The probe keeps track of the number of instances of the target that currently exist, and how many have been created since the program was started.
// The probe is to respond with appropriate tracking information when the class instance containing the probe is queried.
// It will be necessary to figure out the best way to present the query.
// Demonstrate your probe on a class with multiple instances.
//Use operator overloading in the Probe class to increment and decrement its member data.
//Overload the ostream operator to support printing of information of the class Probe.
//Overload the ostream operator to support printing of information of the class Target.
// Hint : the information that a Target should stream is the information that its contained Probe can stream.
//Use the delete keyword to delete the copy constructor and assignment operator for the probe. (see Section 13.1.6 in Lippman)

#if 0
int Employee::ourInstanceCount = 0;
#else
namespace
{
    int ourInstanceCount;
}
#endif

    //Probe::Probe()
    //{
    //}

    Probe::Probe(int instCount){
        ourInstanceCount = instCount;
    }

    //Overload the + operator then return a copy of Probe
    Probe Probe::operator+(Probe a1)
    {
        ++ourInstanceCount;
        return Probe(a1.getInstanceCount() + getInstanceCount());
    }

    //Overload the pre- and postfix
    //  autoincrement operators

    //Increment then return incremented Probe
    Probe Probe::operator++(int)
    {
        ++ourInstanceCount;
        return Probe(getInstanceCount());
    }

    //Increment then return a copy of Probe
    Probe Probe::operator++()
    {
        ++ourInstanceCount;
        return Probe(getInstanceCount());
    }

    //Decrement then return incremented Probe
    Probe Probe::operator--(int)
    {
        --ourInstanceCount;
        return Probe(getInstanceCount());
    }

    //Decrement then return a copy of Probe
    Probe Probe::operator--()
    {
       --ourInstanceCount;
       return Probe(getInstanceCount());
    }

int Probe::getInstanceCount()
{
    return ourInstanceCount;
}

std::ostream& operator<<(std::ostream& os, const Probe& probe)
{
    os << probe.getInstanceCount();

    return os;
}