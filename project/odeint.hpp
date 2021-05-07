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
template<typename F, typename X> void RK4Step(F der, std::vector<X>& x, X& tau, int& index){
    //this is fine like this, but the problem is that these could be more compact...
    vector<X> k1(x.size()), k2(x.size()), k3(x.size()), k4(x.size());
    k1 = tau * der(x);
    k2 = tau * der(x + 0.5 * k1);
    k3 = tau * der(x + 0.5 * k2);
    k4 = tau * der(x + k3);
    x += (k1 + 2 * k2 + 2 * k3 + k4)/6.0; 
}