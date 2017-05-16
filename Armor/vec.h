#define ARMA_DONT_USE_WRAPPER
#define ARMA_NO_DEBUG
#include <armadillo>

namespace Armor {

template <class Type, uint Size>
class Vec
{
private:
    Type data[Size];
    typedef typename arma::Mat<Type>::template fixed<Size,1> ArmaType;
public:
    Vec() {;}
    inline Vec(const ArmaType & a) {
        for (uint i = 0; i < Size; ++i) {
            data[i] = a[i];
        }
    }
    inline Type operator [](uint index) const {
        return data[index];
    }
    inline Type & operator[](uint index) {
        return data[index];
    }
    inline ArmaType arma() const {
        return ArmaType(&(data[0]));
    }
    inline operator ArmaType() const {
        return this->arma();
    }
    inline const Vec<Type, Size> & operator=(const Vec<Type, Size> & other) {
        for (uint i = 0; i < Size; ++i) {
            data[i] = other[i];
        }
        return *this;
    }
    inline const Vec<Type, Size> & operator=(const ArmaType & other) {
        for (uint i = 0; i < Size; ++i) {
            data[i] = other[i];
        }
        return *this;
    }
    uint size() const {
        return Size;
    }
};

template <class Type>
inline const Vec<Type, 3> & operator=(Vec<Type, 3> & vec, const typename arma::Mat<Type>::template fixed<3,1> & other) {
    vec[0] = other[0];
    vec[1] = other[1];
    vec[2] = other[2];
    return vec;
}

template <class Type, uint Size>
inline double dot(const Vec<Type, Size> & a, const Vec<Type, Size> & b) {
    return arma::dot(a.arma(), b.arma());
}

template <class Type, uint Size>
inline typename arma::Mat<Type>::template fixed<Size,1> operator+(const Vec<Type, Size> & a, const Vec<Type, Size> & b) {
    return a.arma() + b.arma();
}

template <class Type, uint Size>
inline typename arma::Mat<Type>::template fixed<Size,1> operator-(const Vec<Type, Size> & a, const Vec<Type, Size> & b) {
    return a.arma() - b.arma();
}

template <class Type, uint Size>
inline typename arma::Mat<Type>::template fixed<Size,1> operator*(Type number, const Vec<Type, Size> & a) {
    return number * a.arma();
}


template <class Type, uint Size>
inline typename arma::Mat<Type>::template fixed<Size,1> operator/(const Vec<Type, Size> & a, Type number) {
    return a.arma() / number;
}

}
