#include <iostream>
#include "process.hpp"


// Constructor with arguments
Process::Process(long long PID, long long start_address) {
    this->PID = PID;
    this->start_address = start_address;
}

// Default constructor
Process::Process() {
    this->PID = 0;
    this->start_address = 0;
}

long long Process::getPID() { return PID; }
long long Process::getStartAddress() { return start_address; }

void Process::setPID(long long PID) { this->PID = PID; }
void Process::setStartAddress(long long start_address) { this->start_address = start_address; }