#include <iostream>
#include <iomanip>
/*
//as this is just an a newton iterator, the point is to use templates and give functions to functions.
//using the slides as source
//make the iterator
//make it stop by a function that returns a boolean that causes it to stop if false.
WITHOUT STD=C++11 THIS DOES NOT RUN
*/
//templates: Function, Xoordinate, Epsilon,

template<typename X> X sq(X x){
    return x*x - 612.0;
}

template<typename X> X df(X x){
    return 2.0*x;
}

template<typename F, typename DF, typename X, typename E, typename TOL> X integrate(F f,DF df, X x0, E eps, TOL tol){
    X x1 = x0 - f(x0)/df(x0);
    while (abs(df(x0)) > eps){
        if(abs(x0-x1) < tol) break;
        x0 = x1;
        x1 = x0 - f(x0)/df(x0);
        
    }
    return x1;
}

//argc and argv[] is not needed
int main() {
    std::cout << "Newton-iterator started!" << std::endl;
    double x0 = 0.0, x1 = 1.0;
    int n = 100;
    double result = integrate(sq<double>,df<double>, 10.0,1e-10,1e-10);
    std::setprecision(15);
    std::cout << std::setprecision(15) << "Result =\t" << result << std::endl;
    std::cout << "Stopped." << std::endl;
    return 0;
}

