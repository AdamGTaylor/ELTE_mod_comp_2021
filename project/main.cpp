//standard libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>

//my headers
#include "odeint.hpp"
#include "vectorN.hpp"

int main(int, char**) {
    //testing my vector ops
    std::cout << "Hello, world!\n";
    std::vector<double> vec1(5,2);
    std::vector<double> vec2(5,-2);
    std::vector<double> vec3;
    vec3 = vec1 + vec2;
    print_vector(vec1);
    print_vector(vec2);
    print_vector(vec3);
    std::cout << "\n Test Finished";
}
