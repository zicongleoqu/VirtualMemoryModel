#include <iostream>
#include "open.hpp"

using namespace std;

// Constructor
Open::Open(int N, int P) {
    this->N = N;
    this->P = P;
    this->table_size = N / P;
    hash_table = new long long[N];
    pid_table = new long long[table_size];
    for (int i = 0; i < table_size; i++) {
        pid_table[i] = -1;
    }
    current_pid_table_size = 0;
}

Open::~Open() {
    delete[] hash_table;
    delete[] pid_table;
}

int Open::h1(long long k) {
    return k % table_size;
}

int Open::h2(long long k) {
    int result = (k/table_size) % table_size;
    if (result % 2 == 0) {
        {
            ++result;
        }
    }
    return result;
}

int Open::pid_exist(long long PID) {
    int i = 0;
    int index = 0;
    int initial_index = h1(PID);
    bool first_iteration = true;
    while (true){
        index = (h1(PID) + i * h2(PID)) % table_size;
        if (pid_table[index] == -1) {
            return -1;
        }
        else if (pid_table[index] == PID){
            return index;
        }else if (index == initial_index && first_iteration == false){
            return -1;
        }
        i++;
        first_iteration = false;
    }
}

void Open::insert_operation(long long PID) {
    if (current_pid_table_size >= table_size) {
        cout << "failure" << endl;
    }
    else {
        int i = 0;
        int index = 0;
        int check_pid_table = pid_exist(PID);
        if (check_pid_table == -1) {
            while (true) {
            index = (h1(PID) + i * h2(PID)) % table_size;
            if (pid_table[index] == 0 || pid_table[index] == -1) {
                pid_table[index] = PID;
                current_pid_table_size++;
                cout << "success" << endl;
                break;
            }
            i++;
            }
        }else {
            cout << "failure" << endl;
        }
    }
}

void Open::search_operation(long long PID) {
    int check_pid_table = pid_exist(PID);
    if (check_pid_table == -1) {
        cout << "not found" << endl;
    } else {
        cout << "found " << PID << " in " << check_pid_table << endl;
    }
}

void Open::write_operation(long long PID, int ADDR, long long x) {
    int check_pid_table = pid_exist(PID);
    if (check_pid_table == -1 || ADDR >= P){
        cout << "failure" << endl;
    }else {
        int memory_location = check_pid_table * P + ADDR;
        hash_table[memory_location] = x;
        cout << "success" << endl;
    }
}

void Open::read_operation(long long PID, int ADDR) {
    int check_pid_table = pid_exist(PID);
    if (check_pid_table == -1 || ADDR >= P){
        cout << "failure" << endl;
    }else {
        int stored_value = hash_table[check_pid_table * P + ADDR];
        cout << ADDR << " " << stored_value << endl;
    }
}

void Open::delete_operation(long long PID) {
    int check_pid_table = pid_exist(PID);
    if (check_pid_table == -1){
        cout << "failure" << endl;
    }else {
        pid_table[check_pid_table] = 0;
        current_pid_table_size--;
        cout << "success" << endl;
    }
}