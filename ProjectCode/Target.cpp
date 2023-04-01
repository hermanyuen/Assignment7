#include "Target.h"

#include <ostream>

//Define a probe(class Probe) that can be inserted into a class (class Target) as a test coverage device. 
// (Note : the data and function members of the probe cannot be static. The probe itself must be declared static in the Target class.)  
// The probe keeps track of the number of instances of the target that currently exist, and how many have been created since the program was started.
// The probe is to respond with appropriate tracking information when the class instance containing the probe is queried.
// It will be necessary to figure out the best way to present the query.
// Demonstrate your probe on a class with multiple instances.
//Use operator overloading in the Probe class to incrementand decrement its member data.
//Overload the ostream operator to support printing of information of the class Probe.
//Overload the ostream operator to support printing of information of the class Target.
// Hint : the information that a Target should stream is the information that its contained Probe can stream.
//Use the delete keyword to delete the copy constructorand assignment operator for the probe. (see Section 13.1.6 in Lippman)

//TODO: implement

Target::Target() {
    ++instances;
}


Target::~Target()
{
    --instances;
}

//const Probe* Target::getTargetProbe() {
//    //const Probe* temp = &instances;
//    return &instances;
//    // return temp;
//    //return instances;
//}

std::ostream& operator<<(std::ostream& os, const Target& targetInstance)
{
    os << targetInstance.instances.getInstanceCount;
    //os << targetInstance.getTargetProbe();//.getInstanceCount();
    return os;
}