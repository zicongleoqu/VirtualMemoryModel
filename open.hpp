#ifndef _OPEN_HPP_
#define _OPEN_HPP_

#include <iostream>

class Open {
    public:

        // Constructor
        Open(int N, int P);

        ~Open();

        int h1(long long k);

        int h2(long long k);

        int pid_exist(long long PID);

        void insert_operation(long long PID);

        void search_operation(long long PID);

        void write_operation(long long PID, int ADDR, long long x);

        void read_operation(long long PID, int ADDR);

        void delete_operation(long long PID);

    private:

        // Private member variables
        int table_size;
        int N;
        int P;
        int current_pid_table_size;
        long long *hash_table;
        long long *pid_table;
};
#endif