#include <iostream>
#include "ExprTemplTypeSize/vector.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;


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

    d = 2.0*d + a*2.0 + (b - c)/2.0 - 3.0*(a - b);

    cout << d[0] << endl << d[1] << endl << d[2] << endl;

    exprtempltypesize::Vec<int, 3> e;
    exprtempltypesize::Vec<int, 3> f;
    exprtempltypesize::Vec<int, 3> g;
    exprtempltypesize::Vec<int, 3> h;

    e[0] = 1;
    e[1] = 2;
    e[2] = 3;

    f[0] = 3;
    f[1] = 2;
    f[2] = 1;

    g[0] = 1;
    g[1] = 2;
    g[2] = 1;

    h[0] = 0;
    h[1] = 0;
    h[2] = 0;

    h = 2*h + e*2 + (f - g)/2 - 3*(e - f);

    cout << h[0] << endl << h[1] << endl << h[2] << endl;

    return 0;
}
