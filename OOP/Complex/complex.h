#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
using namespace std;

template<typename T>
class complex {
public:
    complex (T r = 0, T i = 0)
        : re(r), im(i) 
    {}
    complex& operator += (const complex&);
    T real() const {
        return re;
    }
    T imag () const {
        return im;
    }
private:
    T re, im;
    friend complex& __doapl(complex*, const complex&); // do assignment plus
};

template<typename T>
inline complex<T>& __doapl(complex<T>* ths, const complex<T>& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

template<typename T>
inline complex<T>& complex<T>::operator += (const complex<T>& r) {
    return __doapl (this, r);
}



#endif