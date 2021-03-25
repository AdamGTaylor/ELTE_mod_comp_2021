#include <iostream>
#include <iomanip>

#include "vector2D.hpp"

int main() {
    std::cout << "Vector 2D program started!" << std::endl;
    std::cout << "TESTING VECTOR2D_H functions!\n-----------------------------" << std::endl;
    //creating 2 vectors for manipulation! with 1 double
    double test_num = 2.0;
    double test_arc = -90;
    Vector2D<double> v1{test_num, test_num}, v2{test_num, -test_num};
    std::cout << "v1:\t\t\t" << v1 << std::endl;
    std::cout << "v2:\t\t\t" << v2 << std::endl;
    std::cout << "op+\tv1+v2\t\t" << (v1+v2) << std::endl;
    std::cout << "op-\tv1-v2\t\t" << (v1-v2) << std::endl;
    std::cout << "op*\tv1 * v1(1)\t"<< (v1*v1.x) << std::endl;
    std::cout << "op*\tv1(1) * v1\t"<< (v1*v1.x) << std::endl;
    std::cout << "op/\tv1 / v1(1)\t" << (v1 / v1.x) << std::endl;
    std::cout << "dot\tv1 x v2\t\t" << dot(v1,v2) << std::endl;
    std::cout << "ska\tv1 * v2\t\t" << skal(v1,v2) << std::endl;
    std::cout << "rot\t90(deg) * v2\t" << rotate(test_arc,v1) << std::endl;
    std::cout << "TESTING VECTOR2D stuct funcs!\n-----------------------------" << std::endl;
    std::cout << "op+=\t\t\t" << (v1+=v2) << std::endl;
    std::cout << "op-=\t\t\t" << (v1-=v2) << std::endl;
    std::cout << "norm\tv1.norm()\t" << v1.norm() <<std::endl;
    std::cout << "norm\tv2.norm()\t" << v2.norm() <<std::endl;
    std::cout << "-----------------------------\nEnded!" << std::endl; 
    return 0;
}