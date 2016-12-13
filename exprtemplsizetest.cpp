/*
#include <iostream>
#include "ExprTemplSize/vector.h"
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    exprtemplsize::Vec<3> a;
    exprtemplsize::Vec<3> b;
    exprtemplsize::Vec<3> c;
    exprtemplsize::Vec<3> d;

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    b[0] = 3;
    b[1] = 2;
    b[2] = 1;

    c[0] = 1;
    c[1] = 2;
    c[2] = 1;

    d[0] = 0;
    d[1] = 0;
    d[2] = 0;

    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < 100000000; i++) {
        d = d + a + (b - c) - (a - b);
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "time in milliseconds:" << elapsed.count() << '\n';

    cout << d[0] << endl << d[1] << endl << d[2] << endl;


    return 0;
}
*/
