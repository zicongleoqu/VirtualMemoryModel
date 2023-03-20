#ifndef _ORDERED_HPP_
#define _ORDERED_HPP_

#include <iostream>
#include <vector>
#include "process.hpp"

class Ordered {
    public:

        // Constructor
        Ordered(int N, int P);

        ~Ordered();

        int h1(long long k);

        int pid_exist(long long PID);

        void insert_operation(long long PID);

        void search_operation(long long PID);

        void write_operation(long long PID, int ADDR, long long x);

        void read_operation(long long PID, int ADDR);

        void delete_operation(long long PID);

        void print_operation(int m);

    private:

        // Private member variables
        int table_size;
        int N;
        int P;
        long long *hash_table;
        std::vector<std::vector<Process>> process_table = {};
        std::vector<long long> page_table = {};
};
#endif