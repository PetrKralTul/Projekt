#include <iostream>
//#define ARMA_DONT_USE_WRAPPER //clapack wrapper
#include "Armor/vec.h"
//#include <armadillo>
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

    double * d1 = new double[1000000];

    auto start1 = std::chrono::system_clock::now();

    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < 1000000; ++i) {
            pom1 = pom1 + v1[i];
        }
    }

    auto end1 = std::chrono::system_clock::now();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "cas pro Vec<double,3>:" << elapsed1.count() << endl << endl;

    auto start4 = std::chrono::system_clock::now();

    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 1000000; ++i) {
            d1[i] = v1[i].dot(v2[i]);
        }
    }

    auto end4 = std::chrono::system_clock::now();
    auto elapsed4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4);
    std::cout << "skalarni soucin Vec<double,3>:" << elapsed4.count() << endl << endl;

    cout << pom1[0] << endl << pom1[1] << endl << pom1[2] << endl;

    cout << "skalarni soucin vec double 3:" << d1[0] << endl;

    //Armadillo

    // /*
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

    //std::vector<double> d2;

    double * d2 = new double[1000000];

    auto start2 = std::chrono::system_clock::now();

    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < 1000000; ++i) {
            pom2 = pom2 + a1[i];
        }
    }

    auto end2 = std::chrono::system_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "cas pro arma::vec3:" << elapsed2.count() << endl << endl;


    auto start5 = std::chrono::system_clock::now();

    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 1000000; ++i) {
            d2[i] = dot(a1[i],a2[i]);
        }
    }

    auto end5 = std::chrono::system_clock::now();
    auto elapsed5 = std::chrono::duration_cast<std::chrono::milliseconds>(end5 - start5);
    std::cout << "skalarni soucin arma::vec3:" << elapsed5.count() << endl << endl;

    cout << pom2[0] << endl << pom2[1] << endl << pom2[2] << endl;

    cout << "skalarni soucin arma::vec3:" << d2[0] << endl;

    //fastest


    // */
    raw_arma ra1(1000000);

    for (int i = 0; i < 3000000; ++i) {
        ra1[i] = fRand(-100,100);
    }

    raw_arma ra2(1000000);

    for (int i = 0; i < 3000000; ++i) {
        ra2[i] = fRand(-100,100);
    }

    arma::vec3 pom3;
    pom3[0] = 0;
    pom3[1] = 0;
    pom3[2] = 0;



    double * d3 = new double[1000000];

    auto start3 = std::chrono::system_clock::now();

    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < 1000000; ++i) {
            pom3 = pom3 + ra1.get(i);
        }
    }

    auto end3 = std::chrono::system_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3);
    std::cout << "cas pro raw_arma:" << elapsed3.count() << endl << endl;

    auto start6 = std::chrono::system_clock::now();

    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 1000000; ++i) {
            d3[i] = dot(ra1.get(i),ra2.get(i));
        }
    }

    auto end6 = std::chrono::system_clock::now();
    auto elapsed6 = std::chrono::duration_cast<std::chrono::milliseconds>(end6 - start6);
    std::cout << "skalarni soucin raw_arma:" << elapsed6.count() << endl << endl;

    cout << pom3[0] << endl << pom3[1] << endl << pom3[2] << endl;

    cout << "skalarni soucin raw_arma:" << d3[0] << endl;





    //Armor <<-----------




    std::vector<Armor::Vec<double, 3>> va1(1000000);

    for (int i = 0; i < 1000000; ++i) {
        //va1.push_back(Armor::Vec());
        va1[i][0] = fRand(-100,100);
        va1[i][1] = fRand(-100,100);
        va1[i][2] = fRand(-100,100);
    }

    std::vector<Armor::Vec<double, 3>> va2(1000000);

    for (int i = 0; i < 1000000; ++i) {
        //va2.push_back(Armor::Vec<double, 3>());
        va2[i][0] = fRand(-100,100);
        va2[i][1] = fRand(-100,100);
        va2[i][2] = fRand(-100,100);
    }


    Armor::Vec<double, 3> poma1;
    //arma::vec3 poma1;
    poma1[0] = 0;
    poma1[1] = 0;
    poma1[2] = 0;


    double * da1 = new double[1000000];

    //Armor::Vec<double, 3> * va1data = va1.data();

    auto starta1 = std::chrono::system_clock::now();

    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < 1000000; ++i) {
            poma1 = poma1 + va1[i] ; //  Stale potreba rucne pretypovat -- nebo volat .arma() 536 ms vs bez arma() 611 ms -- asi vyreseno
            //poma1 = poma1 + va1[i];
        }
    }

    //zkusit poma1 arma::vec3

    auto enda1 = std::chrono::system_clock::now();
    auto elapseda1 = std::chrono::duration_cast<std::chrono::milliseconds>(enda1 - starta1);
    std::cout << "cas pro Armor::Vec<double,3>:" << elapseda1.count() << endl << endl;

    auto starta4 = std::chrono::system_clock::now();

    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 1000000; ++i) {
            da1[i] = dot(va1[i], va2[i]); // Stale potreba rucne pretypovat -- nebo volat .arma() - vyreseno OK a je rychlejsi nez s arma()
        }
    }

    auto enda4 = std::chrono::system_clock::now();
    auto elapseda4 = std::chrono::duration_cast<std::chrono::milliseconds>(enda4 - starta4);
    std::cout << "skalarni soucin Armor::Vec<double,3>:" << elapseda4.count() << endl << endl;

    cout << poma1[0] << endl << poma1[1] << endl << poma1[2] << endl;

    cout << "skalarni soucin Armor vec double 3:" << da1[0] << endl;

    //cout << va1[0][0] << endl << va1[0][1] << endl << va1[0][2] << endl;

    /*
    arma::vec3 zk1;
    zk1[0] = 1;
    zk1[1] = 2;
    zk1[2] = 3;

    Armor::Vec<double, 3> zk2;
    zk2[0] = 0;
    zk2[1] = 0;
    zk2[2] = 0;

    zk2 = zk1;

    cout << zk2[0] << endl << zk2[1] << endl << zk2[2] << endl;
    */

    cout << va1[0][0] << endl;

    va1[0] = va1[0] / 5.0;

    cout << va1[0][0] << endl;

    return 0;
}
