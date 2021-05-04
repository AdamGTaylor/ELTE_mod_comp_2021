#ifndef VECTORN_HPP
#define VECTORN_HPP
#include <iostream>
#include <ostream>
#include <istream>
#include <math.h>
#include <vector>

//i need a more refined way of handling vectors, multiplication and stuff like this
//this means that i have to extend what vector::operator can understand.
//this leads to more compact formulas
//and not going to use namespace -- programmer friend advice

template<typename X> void print_vector(std::vector<X>& a){
    std::cout << "(";
    for(int i=0; i < a.size(); ++i){
        std::cout<<"\t"<<a[i];
    }
    std::cout << ")\n";
}

//c = a+b
template<typename X> std::vector<X> operator+
(const std::vector<X> &a, const std::vector<X> &b){
    std::vector<X> c(std::max(a.size(),b.size()));
    for(int i=0; i<std::max(a.size(),b.size()); ++i){
        c[i] = a[i] + b[i];
    }
    return c;
}

//c = a-b
template<typename X> std::vector<X> operator-
(const std::vector<X> &a, const std::vector<X> &b){
    std::vector<X> c(std::max(a.size(),b.size()));
    for(int i=0; i<std::max(a.size(),b.size()); ++i){
        c[i] = a[i] - b[i];
    }
    return c
}

//c = scal*vec
template<typename X> std::vector<X> operator *
(const std::vector<X>& vec, const X scalar){
    std::vector<X> c(vec.size());
    for(int i = 0; i < vec.size(), ++i ){
        c[i] = scalar * vec[i];
    }
    return c;
}
//c = vec*scal
template<typename X> std::vector<X> operator *
(const X scalar,const std::vector<X>& vec){
    std::vector<X> c(vec.size());
    for(int i = 0; i < vec.size(), ++i ){
        c[i] = scalar * vec[i];
    }
    return c;
}

//c = vec/scal
template<typename X> std::vector<X> operator /
(const std::vector<X>& vec, const X scalar){
    std::vector<X> c(vec.size());
    for(int i = 0; i < vec.size(), ++i ){
        c[i] = vec[i] / scalar;
    }
    return c;
}

//a += b
template<typename X> std::vector<X> operator +=
(const std::vector<X>&a, const std::vector<X> &b){
    for(int i=0; i<std::max(a.size(),b.size())){
        a[i] += b[i]
    }
}

//a -= b
template<typename X> std::vector<X> operator -=
(const std::vector<X>&a, const std::vector<X> &b){
    for(int i=0; i<std::max(a.size(),b.size())){
        a[i] -= b[i]
    }
}

//a *= b
template<typename X> std::vector<X> operator *=
(const std::vector<X>&a, const std::vector<X> &b){
    for(int i=0; i<std::max(a.size(),b.size())){
        a[i] *= b[i]
    }
}

//a /= b
template<typename X> std::vector<X> operator /=
(const std::vector<X>&a, const std::vector<X> &b){
    for(int i=0; i<std::max(a.size(),b.size())){
        a[i] /= b[i]
    }
}

template<typename X>
std::ostream& operator<<(std::ostream& os, const std::vector<X> vec){
    for(int i=0;i < v.size(); ++i){
        os << vec[i] << "\t";
    }
    return os;
}

//no a/=b, it would only make sense if it were done elementwise



#endif