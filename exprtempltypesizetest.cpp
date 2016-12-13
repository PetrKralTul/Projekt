/*
#include <iostream>
#include "ExprTemplTypeSize/vector.h"
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{

    exprtempltypesize::Vec<double, 3> a;
    exprtempltypesize::Vec<double, 3> b;
    exprtempltypesize::Vec<double, 3> c;
    exprtempltypesize::Vec<double, 3> d;

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


    d = 2.0*d + a*2.0 + (b - c)/2.0 - 3.0*(a - b);

    cout << d[0] << endl << d[1] << endl << d[2] << endl;


    return 0;
}

// 1060 ms
*/
