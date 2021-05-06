//standard libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>

//my headers
#include "odeint.hpp"
#include "vectorN.hpp"

//MAIN LOGIC:
//fail check -> init -> do calcs:
//calcs: copy current -> generate der -> update copy -> save -> update original -> repeat
//saving: each in different files

//my constants in AU and YEAR and kg
const double PI = 4 * atan(1.0);
const double G = 1.9838 * std::pow(10,-29);
const double MPLUSM = 4 * PI * PI;
const double c = 63197.8;
std::string path1= "../../../input_data/";
std::string path2 = "/output/";
std::string inFileName;
std::string outName;

//stuff that is needed for sim and init
//3D 3body sim is burnt into the code but can be changed via arguments
double T;
double dt;
int dim = 3;     //3D for default
int body_count = 3;

//vectors to hold values
std::vector<double> masses;
std::vector<std::vector<double>> trv;  //time,coordinates,velocities... 1+2*D
std::vector<std::vector<double>> trv_new;
std::vector<double> dist;



//fail check -> init -> do calcs:
//calcs: copy current -> generate der -> update copy -> save -> update original -> repeat
//saving: each in different files

//updating distances!
template<typename X>
void updateDistances(std::vector<std::vector<X>>& trv){
    //symmetric equations, only the initial direction has to be considered!
    //    0 1 2  (i)
    //  0 
    //  1 x 
    //  2 x x
    //(j)
    //differences between body_count and indexing!
    std::vector<X> temp_dist(body_count*(body_count-1)/2,0);
    for(int i = 0; i < body_count-1; ++i){
        for(int j = i+1; j < body_count-1; ++j){
            std::vector<double> loc1(dim,0);
            std::vector<double> loc2(dim,0);
            for(int k=0; k < dim; k++){
                loc1[k] = trv[i][1+k];
                loc2[k] = trv[j][1+k];
            }
            temp_dist[i+j] = abs_vec(loc1 - loc2);
        }
    }
    dist = temp_dist;
}

//updating old to new
void updateTRV(){
    trv = trv_new;
}

void initSystem( ){
    std::string filename = path1 + inFileName;
    std::ifstream inFile(filename);
    if(inFile.good()){
        std::vector<double> temp_masses(body_count);
        std::vector<std::vector<double>> temp_trv;
        for(int i=0; i < body_count; ++i){
            inFile >> temp_masses[i];
            //temp_vec = [0,x1,x2,x3,v1,v2,v3];, while t0=0
            std::vector<double> temp_vec((1+2*dim),0);
            for(int f = 0; f < 2; ++f){
                for(int j = 0; j< dim; ++j){
                    inFile >> temp_vec[1+j+f*dim];
                }
            }
            temp_trv.push_back(temp_vec);
        }
        //if this is done, we can copy
        masses = temp_masses;
        trv = temp_trv;
        updateDistances(trv);
        std::cout << "Loading finished!" << std::endl;
    } else {
        std::cout << "Something went wrong while loading!\nStopping!" << std::endl;
    }
}

//probably remain unused
template<typename X>
void reset_mat(std::vector<std::vector<X>> mat){
    for(int i=0; i<mat.size(); ++i){
        std::vector<X> nuller(mat[i].size(),0);
        mat[i] = nuller;
    }
}

//returns only one, but takes to... 3 body -> 6 calls
// the info carrier has to be used and l

template<typename X>
std::vector<X> f(const std::vector<std::vector<X>> trv, int index){
    double t = trvd[0];
    std::vector<X> r(dim,0);
    for(int i = 0; i < dim; ++i){

    }
}

//InFileName,BodyCount,Dim
int main(int argc, char* argv[]) {
    //testing my vector ops, if there is no vectorN.hpp header, won't work
    std::cout << "Hello there, Three Body, Binary System orbiting planet!\n";
    std::vector<double> vec1(5,2);
    std::vector<double> vec2(5,-2);
    std::vector<double> vec3;
    vec3 = vec1 + vec2;
    print_vector(vec1);
    print_vector(vec2);
    print_vector(vec3);
    std::cout << "\nTest Finished" << std::endl;
    std::cout << "Arg_num: " << argc << std::endl;
    //the operation system is th first in the arg list.
    if(argc = 1){
        inFileName = "test.txt";
        std::string filename1 = path1 + inFileName;
        std::cout <<"Location"<< (filename1) << std::endl;
        std::cout << "3D simulation assumed! Errors may rise!" << std::endl;
        dim = 3;
        body_count = 3;
        std::cout << "Chosed params: " << dim << "D\tBodies:" << body_count << std::endl;        
    }else if(argc = 2){
        inFileName = argv[1];
        std::cout << "3D simulation assumed! Errors may rise!" << std::endl;
        dim = 3;
        body_count = 3;
        std::cout << "Chosed params: " << dim << "D\tBodies:" << body_count << std::endl;
    } else if(argc = 3){
        inFileName = argv[1];
        dim = atoi(argv[2]);
        body_count = 3;
    } else {
        inFileName = argv[1];
        dim = atoi(argv[2]);
        body_count = atoi(argv[3]);
    }
    
    //file loading - init

    initSystem();
    print_vec_set(trv); 
    print_vector(masses);


    std::cout << "Finished" << std::endl;
    return 0;
}
