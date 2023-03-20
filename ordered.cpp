#include <iostream>
#include <vector>
#include "ordered.hpp"

using namespace std;

// Constructor
Ordered::Ordered(int N, int P) {
    this->N = N;
    this->P = P;
    this->table_size = N / P;
    hash_table = new long long[N];
    process_table.resize(table_size);
    page_table.resize(table_size);
    for (int i = 0; i < table_size; i++) {
        page_table[i] = i;
    }
}

Ordered::~Ordered() {
    delete[] hash_table;
}

int Ordered::h1(long long k) {
    return k % table_size;
}

int Ordered::pid_exist(long long PID) {
    int index = h1(PID);
    for (int i = 0; i < process_table[index].size(); i++) {
        if (process_table[index][i].getPID() == PID) {
            return i;
        }
    }
    return -1;
}

void Ordered::insert_operation(long long PID) {
    if (page_table.size() <= 0) {
        cout << "failure" << endl;
    }
    else {
        int index = h1(PID);
        int check_pid = pid_exist(PID);
        if (check_pid >= 0){
            cout << "failure" << endl;
        }
        else if (check_pid == -1){
            Process new_process(PID, page_table.back() * P);
            page_table.pop_back();
            int desired_index = -1;
            for (int i = 0; i < process_table[index].size(); i ++) {
                if (process_table[index][i].getPID() < PID) {
                    desired_index = i;
                    break;
                }
            }
            if (process_table[index].size() == 0 || desired_index == -1) {
                process_table[index].push_back(new_process);
            }else {
                process_table[index].insert(process_table[index].begin() + desired_index, new_process);
            }
            cout << "success" << endl;
        }
    }
}

void Ordered::search_operation(long long PID) {
    int check_pid = pid_exist(PID);
    int index = h1(PID);
    if (check_pid >= 0) {
        cout << "found " << PID << " in " << index << endl;
    } else {
        cout << "not found" << endl;
    }
}

void Ordered::write_operation(long long PID, int ADDR, long long x) {
    int check_pid = pid_exist(PID);
    int index = h1(PID);
    if (check_pid == -1 || ADDR >= P || ADDR < 0) {
        cout << "failure" << endl;
    }else {
        int destination_index = process_table[index][check_pid].getStartAddress() + ADDR;
        hash_table[destination_index] = x;
        cout << "success" << endl;
    }
}

void Ordered::read_operation(long long PID, int ADDR) {
    int check_pid = pid_exist(PID);
    int index = h1(PID);
    if (check_pid == -1 || ADDR >= P || ADDR < 0) {
        cout << "failure" << endl;
    }else {
        int destination_index = process_table[index][check_pid].getStartAddress() + ADDR;
        cout << ADDR << " " << hash_table[destination_index] << endl;
    }
}

void Ordered::delete_operation(long long PID) {
    int check_pid = pid_exist(PID);
    int index = h1(PID);
    if (check_pid == -1) {
        cout << "failure" << endl;
    } else {
        int freed_page_number = process_table[index][check_pid].getStartAddress() / P;
        page_table.push_back(freed_page_number);
        process_table[index].erase(process_table[index].begin() + check_pid);
        cout << "success" << endl;
    }
}

void Ordered::print_operation(int m) {
    if (process_table[m].size() == 0) {
        cout << "chain is empty" << endl;
    } else {
        for (int i = 0; i < process_table[m].size(); i++) {
            if (i == process_table[m].size() - 1) {
                cout << process_table[m][i].getPID() << endl;
            } else {
                cout << process_table[m][i].getPID() << " ";
            }
        }
    }
}