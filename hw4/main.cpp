#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
//even a list would be good, but i very much like vector

//here is the diff equation, needed to be solved
//y'(t) = 1 + y^2 , y(0) = 0
//newton, runge-kutta, analytic
//notes for me
//what have i done here is that i need the separate solving methods to be defined, and i will run them in the same function
//the correct way of doing this is to separate them further (cuz the solving methods are functions too), as i will do that in the project work.
//here it doesnt really matter, i would only call them once

//defining it
double f(double y){
    return 1 + y*y;
}


//newton
template<typename F> std::vector<double> Newton(F f, double dt, int t1, double y_0){
    std::vector<double> result(t1);
    result[0] = y_0;
    //at i=0 is y_0;
    for(int i = 1; i < t1; i++){
        result[i] = result[i-1] + dt * f(result[i-1]);
    }
    return result;
}
//runge-kutta
template<typename F> std::vector<double> RK(F f, double dt, int t1, double y_0){
    std::vector<double> result(t1);
    result[0] = y_0;
    double temp;
    double k1,k2,k3,k4;
    //have to follow what was shown
    for(int i = 1; i < t1; i++){
        temp = result[i - 1];
        k1 = f(temp);
        k2 = f(temp + dt * k1 / 2.0 );
        k3 = f(temp + dt * k2 / 2.0 );
        k4 = f(temp + dt * k3);
        result[i] = temp + dt * (k1 + 2* k2 + 2*k3 + k4) / 6; 
    }
    return result;
}

//analytic
template<typename F> std::vector<double> Analytic(F f, double dt, int t1, double y_0){
    std::vector<double> result(t1);
    result[0] = y_0;
    for(int i = 1; i < t1; i++){
        result[i] = tan(i*dt);
    }
    return result;
}


int main(int, char**) {
    std::cout << "Started!";
    //init
    double y0 = 0;
    int steps = 1e4;
    double dt = 1e-4;       //okey, 1e-3, you are dangerous, anything above prints inf
    std::vector<double> res_ne, res_rk, res_an;
    res_ne = Newton(f,dt,steps,y0);
    res_rk = RK(f,dt,steps,y0);
    res_an = Analytic(f,dt,steps,y0);   

    std::ofstream file;
    file.open("hw4_results.csv"); //comma separated
    file << "#Newton,RK,Analytic\n"; 

    for(int i = 0; i< res_ne.size(); i++){
        //std::cout << "Results:\t" << res_ne[i] << ",\t" << res_rk[i] << ",\t" << res_an[i] << std::endl;
        //pandas can skip #-ed lines
        file << res_ne[i] << "," << res_rk[i] << "," << res_an[i] << "\n";
    } 
    return 0;
}
