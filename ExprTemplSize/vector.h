namespace exprtemplsize {

#include <vector>
#include <assert.h>

template <typename E>
class VecExpression {
  public:
    double operator[](uint i) const { return static_cast<E const&>(*this)[i];     }
    uint size()               const { return static_cast<E const&>(*this).size(); }

    // The following overload conversions to E, the template argument type;
    // e.g., for VecExpression<VecSum>, this is a conversion to VecSum.
    operator E&()             { return static_cast<      E&>(*this); }
    operator E const&() const { return static_cast<const E&>(*this); }
};



template <uint N>
class Vec : public VecExpression<Vec<N>> {
    double elems[N];

  public:
    double operator[](uint i) const { return elems[i]; }
    double &operator[](uint i)      { return elems[i]; }
    uint size() const               { return N; }

    Vec() {} //zmena

    // A Vec can be constructed from any VecExpression, forcing its evaluation.
    template <typename E>
    Vec(VecExpression<E> const& vec) { //zmena
        for (uint i = 0; i != N; ++i) { //zmena
            elems[i] = vec[i];
        }
    }

    template <typename E>
    const Vec& operator=(VecExpression<E> const& v) {
        for (size_t i = 0; i != v.size(); ++i) {
            elems[i] = v[i];
        }
        return *this;
    }

};




template <typename E1, typename E2>
class VecSum : public VecExpression<VecSum<E1, E2> > {
    E1 const& _u;
    E2 const& _v;

public:
    VecSum(VecExpression<E1> const& u, VecExpression<E2> const& v) : _u(u), _v(v) {
        assert(u.size() == v.size());
    }

    double operator[](uint i) const { return _u[i] + _v[i]; }
    uint size()               const { return _v.size(); }
};




template <typename E1, typename E2>
VecSum<E1,E2> const
operator+(VecExpression<E1> const& u, VecExpression<E2> const& v) {
   return VecSum<E1, E2>(u, v);
}




template <typename E1, typename E2>
class VecSub : public VecExpression<VecSub<E1, E2> > {
    E1 const& _u;
    E2 const& _v;

public:
    VecSub(VecExpression<E1> const& u, VecExpression<E2> const& v) : _u(u), _v(v) {
        assert(u.size() == v.size());
    }

    double operator[](uint i) const { return _u[i] - _v[i]; }
    uint size()               const { return _v.size(); }
};




template <typename E1, typename E2>
VecSub<E1,E2> const
operator-(VecExpression<E1> const& u, VecExpression<E2> const& v) {
   return VecSub<E1, E2>(u, v);
}

template <typename E>
class Multi : public VecExpression<Multi<E> > {
    double _s;
    E const& _v;

public:
    Multi(double s, VecExpression<E> const& v) : _v(v) {
        _s = s;
    }

    double operator[](uint i) const { return _s * _v[i]; }
    uint size()               const { return _v.size(); }
};

template <typename E>
Multi<E> const
operator*(double s, VecExpression<E> const& v) {
   return Multi<E>(s, v);
}

}
