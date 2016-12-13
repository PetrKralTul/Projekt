namespace exprtempltypesize {

#include <assert.h>

template <class Type, typename E>
class VecExpression {
  public:
    Type operator[](uint i) const { return static_cast<E const&>(*this)[i];     }
    uint size()               const { return static_cast<E const&>(*this).size(); }
    operator E&()             { return static_cast<      E&>(*this); }
    operator E const&() const { return static_cast<const E&>(*this); }
};

template <class Type, uint N>
class Vec : public VecExpression<Type, Vec<Type, N>> {
    Type elems[N];

  public:
    Type operator[](uint i) const { return elems[i]; }
    Type &operator[](uint i)      { return elems[i]; }
    uint size() const               { return N; }

    Vec() {}

    template <typename E>
    Vec(VecExpression<Type, E> const& vec) {
        for (uint i = 0; i != N; ++i) {
            elems[i] = vec[i];
        }
    }

    template <typename E>
    const Vec& operator=(VecExpression<Type, E> const& v) {
        for (size_t i = 0; i != v.size(); ++i) {
            elems[i] = v[i];
        }
        return *this;
    }

};




template <class Type, typename E1, typename E2>
class VecSum : public VecExpression<Type, VecSum<Type, E1, E2> > {
    E1 const& _u;
    E2 const& _v;

public:
    VecSum(VecExpression<Type, E1> const& u, VecExpression<Type, E2> const& v) : _u(u), _v(v) {
        assert(u.size() == v.size());
    }

    Type operator[](uint i) const { return _u[i] + _v[i]; }
    uint size()             const { return _v.size(); }
};




template <class Type, typename E1, typename E2>
VecSum<Type, E1,E2> const
operator+(VecExpression<Type, E1> const& u, VecExpression<Type, E2> const& v) {
   return VecSum<Type, E1, E2>(u, v);
}


template <class Type, typename E1, typename E2>
class VecSub : public VecExpression<Type, VecSub<Type, E1, E2> > {
    E1 const& _u;
    E2 const& _v;

public:
    VecSub(VecExpression<Type, E1> const& u, VecExpression<Type, E2> const& v) : _u(u), _v(v) {
        assert(u.size() == v.size());
    }

    Type operator[](uint i) const { return _u[i] - _v[i]; }
    uint size()             const { return _v.size(); }
};




template <class Type, typename E1, typename E2>
VecSub<Type, E1,E2> const
operator-(VecExpression<Type, E1> const& u, VecExpression<Type, E2> const& v) {
   return VecSub<Type, E1, E2>(u, v);
}

template <class Type, typename E>
class Multi : public VecExpression<Type, Multi<Type, E> > {
    E const& _v;
    Type _s;

public:
    Multi(Type s, VecExpression<Type, E> const& v) : _v(v) {
        _s = s;
    }

    Type operator[](uint i) const { return _s * _v[i]; }
    uint size()             const { return _v.size(); }
};

template <class Type, typename E>
Multi<Type, E> const
operator*(Type s, VecExpression<Type, E> const& v) {
   return Multi<Type, E>(s, v);
}

template <class Type, typename E>
Multi<Type, E> const
operator*(VecExpression<Type, E> const& v, Type s) {
   return Multi<Type, E>(s, v);
}



template <class Type, typename E>
class Div : public VecExpression<Type, Div<Type, E> > {
    Type _s;
    E const& _v;

public:
    Div(Type s, VecExpression<Type, E> const& v) : _v(v) {
        _s = s;
    }

    Type operator[](uint i) const { return _v[i] / _s; }
    uint size()             const { return _v.size(); }
};

template <class Type, typename E>
Div<Type, E> const
operator/(VecExpression<Type, E> const& v, Type s) {
   return Div<Type, E>(s, v);
}

// 1060 ms

}
