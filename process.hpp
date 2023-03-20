#ifndef _PROCESS_HPP_
#define _PROCESS_HPP_

#include <iostream>

class Process {
    public:

        // Constructors
        Process();
        Process(long long PID, long long start_address);

        long long getPID();
        long long getStartAddress();

        void setPID(long long PID);
        void setStartAddress(long long start_address);
        
    private:

        // Private member variables
        long long PID;
        long long start_address;
};
#endif