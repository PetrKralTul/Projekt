#include <iostream>
#include <armadillo>
#include "ExprTemplTypeSize/vector.h"
#include <chrono>

using namespace std;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

class raw_arma {
    double *ptr;
public:
    raw_arma(int size) {
        ptr = new double[3*size];
    }
    inline arma::vec3 get(int i) {
        return arma::Mat<double>::fixed<3,1>(ptr + 3*i);
    }
    double & operator[](int i) {
        return ptr[i];
    }
};

int main(int argc, char *argv[])
{

    std::vector<exprtempltypesize::Vec<double, 3>> v1;

    for (int i = 0; i < 1000000; ++i) {
        v1.push_back(exprtempltypesize::Vec<double, 3>());
        v1[i][0] = fRand(-100,100);
        v1[i][1] = fRand(-100,100);
        v1[i][2] = fRand(-100,100);
    }

    std::vector<exprtempltypesize::Vec<double, 3>> v2;

    for (int i = 0; i < 1000000; ++i) {
        v2.push_back(exprtempltypesize::Vec<double, 3>());
        v2[i][0] = fRand(-100,100);
        v2[i][1] = fRand(-100,100);
        v2[i][2] = fRand(-100,100);
    }

    exprtempltypesize::Vec<double, 3> pom1;
    pom1[0] = 0;
    pom1[1] = 0;
    pom1[2] = 0;

    std::vector<double> d1;

    auto start1 = std::chrono::system_clock::now();

    for (int i = 0; i < 1000000; ++i) {
        pom1 = pom1 + v1[i];
    }

    auto end1 = std::chrono::system_clock::now();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "cas pro Vec<double,3>:" << elapsed1.count() << '\n';



    /*
    for (int i = 0; i < 1000000; ++i) {
        d1.push_back(v1[i].dot(v2[i]));
    }
    */

    cout << pom1[0] << endl << pom1[1] << endl << pom1[2] << endl;

    //cout << d1[0] << endl;

    //Armadillo

    std::vector<arma::vec3> a1;

    for (int i = 0; i < 1000000; ++i) {
        a1.push_back(arma::vec3());
        a1[i][0] = fRand(-100,100);
        a1[i][1] = fRand(-100,100);
        a1[i][2] = fRand(-100,100);
    }

    std::vector<arma::vec3> a2;

    for (int i = 0; i < 1000000; ++i) {
        a2.push_back(arma::vec3());
        a2[i][0] = fRand(-100,100);
        a2[i][1] = fRand(-100,100);
        a2[i][2] = fRand(-100,100);
    }

    arma::vec3 pom2;
    pom2[0] = 0;
    pom2[1] = 0;
    pom2[2] = 0;

    std::vector<double> d2;

    auto start2 = std::chrono::system_clock::now();

    for (int i = 0; i < 1000000; ++i) {
        pom2 = pom2 + a1[i];
    }

    auto end2 = std::chrono::system_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "cas pro arma::vec3:" << elapsed2.count() << '\n';


    /*
    for (int i = 0; i < 1000000; ++i) {
        d2.push_back(dot(a1[i],a2[i]));
    }
    */


    cout << pom2[0] << endl << pom2[1] << endl << pom2[2] << endl;

    //cout << d2[0];

    //fastest

    raw_arma ra1(1000000);

    for (int i = 0; i < 3000000; ++i) {
        ra1[i] = fRand(-100,100);
    }

    raw_arma ra2(1000000);

    for (int i = 0; i < 3000000; ++i) {
        ra2[i] = fRand(-100,100);
    }

    arma::vec3 pom3;
    pom2[0] = 0;
    pom2[1] = 0;
    pom2[2] = 0;



    //double * d3 = new double[1000000];

    auto start3 = std::chrono::system_clock::now();

    for (int i = 0; i < 1000000; ++i) {
        pom3 = pom3 + ra1.get(i);
    }

    auto end3 = std::chrono::system_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3);
    std::cout << "cas pro rucni implementaci:" << elapsed3.count() << '\n';

    /*
    for (int i = 0; i < 1000000; ++i) {
        d3[i] = dot(ra1.get(i),ra2.get(i));
    }
    */

    cout << pom3[0] << endl << pom3[1] << endl << pom3[2] << endl;

    //cout << d3[0] << endl;

    return 0;
}
