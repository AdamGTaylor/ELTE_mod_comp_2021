#include <iostream>
#include <cmath>
#include <fstream>


//globals -- DEFINE?
const double F = 900.0;     //N
const double q = 1.8;       //N/m
const double a = 200.0;     //m
const double h = 35;        //m

//our beloved shape func
double sf(double x){
    return F/q * (cosh(q/F * x) - cosh((q*a*0.5 /F)))+h;
}

//D
template<typename F> double D(F f,double x, double h){
    return (f(x+h) - f(x-h)) / (2*h);
}

//S
template<typename F> double S(F f,double x, double h){
    return (4*D(f,x,h) - D(f,x,2*h))/3;
}

//function core for arclength integral, must be multiplied with dx and summed! - mirror translation for arclength
double arcInt(double a){
    return sqrt(1+a*a);
}

//Richardson extrapolation with O(h^6) error
template<typename F> double df(F f, double x, double dx){
    //D(h) = (f(x+dx) - f(x-dx)) / 2*dx
    //S(h) = (4D(h) - D(2h))/3
    //df = (16S(h) - S(2h))/15 "+ O(h^6)" = (16*(4*D(h) - D(2h) ) - (4*D(2h) - D(4h) ) )/15 = 
    //= ( 16*(4*(f(x+dx)-f(x-dx)) - (f(x+2*dx)- f(x-2*dx))/(6*dx))  - ( 4*(f(x+2*dx)-f(x-2*dx)) - (f(x+4*dx)-f(x-4*dx)))/(12*dx))/15
    //i think its good, but not that easy to type down
    return (16*S(f,x,dx) - 2*S(f,x,2*dx))/15;
}

int main(int, char**) {
    std::cout << "Starting!" << std::endl;
    int n = 10000;
    double dx = a/n;  //cuz [0,a]

    //values for the different methods
    double Mid = 0.0;
    double Trap = 0.0;
    double Simpson = 0.0;       

    for(int i = 0; i < n; i++){
        double dfMid = df(sf, dx/2 + i*dx, dx );
        Mid += arcInt(dfMid) * dx;

        double dfTrap1 = df(sf, i*dx, dx);
        double dfTrap2 = df(sf, (i+1)*dx, dx);
        Trap+= (arcInt(dfTrap1) + arcInt(dfTrap2))/2 * dx;

    }
    //as it was shown, Simpson can be evaluated if the Middle and Trapeze method's result is given by:
    Simpson = (2*Mid + 1*Trap)/3;
    std::cout << "M= " << Mid << "\nT= " << Trap << "\nS= " << Simpson << std::endl;

    std::cout << "Outputting file!" << std::endl;
    std::ofstream file;
    file.open("hw3_results.csv");
    file << Mid << "," << Trap << "," << Simpson << "\n";
    file.close();

    std::cout << "Ended!" << std::endl;
    return 0;
}
