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
template<typename X> std::vector<X> operator +
(const std::vector<X> &a, const std::vector<X> &b){
    std::vector<X> c(std::max(a.size(),b.size()));
    for(int i=0; i<std::max(a.size(),b.size()); ++i){
        c[i] = a[i] + b[i];
    }
    return c;
}

//c = a-b
template<typename X> std::vector<X> operator -
(const std::vector<X> &a, const std::vector<X> &b){
    std::vector<X> c(std::max(a.size(),b.size()));
    for(int i=0; i<std::max(a.size(),b.size()); ++i){
        c[i] = a[i] - b[i];
    }
    return c;
}

//c = vec*scal
template<typename X> std::vector<X> operator *
(const std::vector<X>& vec, const X scalar){
    std::vector<X> c(vec.size());
    for(int i = 0; i < vec.size(); ++i ){
        c[i] = scalar * vec[i];
    }
    return c;
}
//c = scal*vec
template<typename X> std::vector<X> operator *
(const X scalar,const std::vector<X>& vec){
    std::vector<X> c(vec.size());
    for(int i = 0; i < vec.size(); ++i ){
        c[i] = scalar * vec[i];
    }
    return c;
}

//c = vec/scal
template<typename X> std::vector<X> operator /
(const std::vector<X>& vec, const X scalar){
    std::vector<X> c(vec.size());
    for(int i = 0; i < vec.size(); ++i ){
        c[i] = vec[i] / scalar;
    }
    return c;
}

//a += b
template<typename X> void operator +=
(std::vector<X>&a,std::vector<X> &b){
    for(int i=0; i<std::max(a.size(),b.size()); ++i){
        a[i] += b[i];
    }
}

//a -= b
template<typename X> void operator -=
(std::vector<X>&a,std::vector<X> &b){
    for(int i=0; i<std::max(a.size(),b.size()); ++i){
        a[i] -= b[i];
    }
}

//a *= b
/*
template<typename X> std::vector<X> operator *=
(std::vector<X>&a,std::vector<X> &b){
    for(int i=0; i<std::max(a.size(),b.size()); ++i){
        a[i] *= b[i];
    }
}
*/

//a /= b
//no a/=b, it would only make sense if it were done elementwise
/*
template<typename X> std::vector<X> operator /=
(const std::vector<X>&a, const std::vector<X> &b){
    for(int i=0; i<std::max(a.size(),b.size())){
        a[i] /= b[i]
    }
}
*/

template<typename X>
std::ostream& operator<<(std::ostream& os, const std::vector<X> vec){
    for(int i=0;i < v.size(); ++i){
        os << vec[i] << "\t";
    }
    return os;
}



template<typename X>
X abs_vec(std::vector<X> vector){
    double len = 0;
    for(int i=0; i < vector.size(); ++i){
        len += std::pow(vector[i], 2);
    }
    return sqrt(len);
}

template<typename X> 
void print_vec(std::vector<X>& v){
    for(int i=0; i<v.size(); ++i){
        std::cout<< v[i] << " ";
    }
    std::cout<<std::endl;
}

template<typename X>
void print_vec_set(std::vector<std::vector<X>>& v_set){
    for(int i=0; i< v_set.size(); ++i){
        print_vec(v_set[i]); 
    }
}

#endif