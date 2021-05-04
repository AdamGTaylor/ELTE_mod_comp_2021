#pragma once 
#include <iostream>
#include <cmath>
#include <vector>

//here is the integrating methods (collection)
//what we need is: name of the integrator, a function it needs (derivative), original coordinates.
//2D or 3D? WE HAVE TO CARE    
//savefile on every step -> void
//new vector at is not a good choice due to its high memory usage, constant memore allocation
//where is our very handy vector header?
//cord, der_func, stepsize
template<typename X,typename DER, typename TAU> void RK4Step(std::vector<X>& x, TAU& tau, DER der){
    //this is fine like this, but the problem is that these could be more compact...
    vector<X> k1(x.size()), k2(x.size()), k3(x.size()), k4(x.size());
    for(int i=0; i<x.size(), ++i){
        k1[i] = tau * der(x[i]);
        k2[i] = tau * der(x[i] + 0.5 * k1[i]);
        k3[i] = tau * der(x[i] + 0.5 * k2[i]);
        k4[i] = tau * der(x[i] + k3[i]);
        x[i] += (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i])/6.0; 
    }

}