#include <iostream>
#include "open.hpp"
#include "ordered.hpp"

using namespace std;

int main()
{
    long long n_value, p_value, PID, ADDR, x, m;
    string cmd, implementation_mode;

    cin >> implementation_mode;

    if (implementation_mode == "OPEN")
    {
        cin >> cmd;
        cin >> n_value;
        cin >> p_value;
        Open table(n_value, p_value);
        cout << "success" << endl;
        while (cin >> cmd)
        {
            if (cmd == "INSERT")
            {
                cin >> PID;
                table.insert_operation(PID);
            }
            else if (cmd == "SEARCH")
            {
                cin >> PID;
                table.search_operation(PID);
            }
            else if (cmd == "WRITE")
            {
                cin >> PID;
                cin >> ADDR;
                cin >> x;
                table.write_operation(PID, ADDR, x);
            }
            else if (cmd == "READ")
            {
                cin >> PID;
                cin >> ADDR;
                table.read_operation(PID, ADDR);
            }
            else if (cmd == "DELETE")
            {
                cin >> PID;
                table.delete_operation(PID);
            }
            else if (cmd == "END")
            {
                break;
            }
        }
    }
    else if (implementation_mode == "ORDERED")
    {
        cin >> cmd;
        cin >> n_value;
        cin >> p_value;
        Ordered table(n_value, p_value);
        cout << "success" << endl;
        while (cin >> cmd)
        {
            if (cmd == "INSERT")
            {
                cin >> PID;
                table.insert_operation(PID);
            }
            else if (cmd == "SEARCH")
            {
                cin >> PID;
                table.search_operation(PID);
            }
            else if (cmd == "WRITE")
            {
                cin >> PID;
                cin >> ADDR;
                cin >> x;
                table.write_operation(PID, ADDR, x);
            }
            else if (cmd == "READ")
            {
                cin >> PID;
                cin >> ADDR;
                table.read_operation(PID, ADDR);
            }
            else if (cmd == "DELETE")
            {
                cin >> PID;
                table.delete_operation(PID);
            }
            else if (cmd == "PRINT")
            {
                cin >> m;
                table.print_operation(m);
            }
            else if (cmd == "END")
            {
                break;
            }
        }
    }
    return 0;
}