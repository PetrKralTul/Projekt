/*
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{

    cout << "rucni reseni pro test rychlosti" << endl;

    double a[3] = {1, 2, 3};
    double b[3] = {3, 2, 1};
    double c[3] = {1, 2, 1};
    double d[3] = {0, 0, 0};

    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < 100000000; i++) {
        d[0] = d[0] + a[0] + (b[0] - c[0]) - (a[0] - b[0]);
        d[1] = d[1] + a[1] + (b[1] - c[1]) - (a[1] - b[1]);
        d[2] = d[2] + a[2] + (b[2] - c[2]) - (a[2] - b[2]);
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "time in milliseconds:" << elapsed.count() << '\n';

    cout << d[0] << endl << d[1] << endl << d[2] << endl;

    return 0;
}

// 470 ms
*/
