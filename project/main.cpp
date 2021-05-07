//standard libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>
#include <filesystem>
#include <string>
#include <direct.h>


//my headers
//#include "odeint.hpp"
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
double max_steps;
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

//i need this strange being...
template<typename X> void RK4(std::vector<X>& x, X tau, int index){
    //this is fine like this, but the problem is that these could be more compact...
    std::vector<X> k1(x.size()), k2(x.size()), k3(x.size()), k4(x.size());
    k1 = tau * derivative(x,index);
    k2 = tau * derivative(x + 0.5 * k1, index);
    k3 = tau * derivative(x + 0.5 * k2, index);
    k4 = tau * derivative(x + k3, index);
    x += (k1 + 2.0 * k2 + 2.0 * k3 + k4)/6.0; 
}

//print infos
void print_infos(){
    std::cout << "Param List:" << std::endl;
    std::cout << "Location:\t" << path1 + inFileName <<std::endl;;
    std::cout << "Dimension:\t" << dim << std::endl;
    std::cout << "Body Count:\t" << body_count << std::endl;
    std::cout << "Time period(Y):\t" << T << std::endl;
    std::cout << "Stepsize(Y):\t" << dt << std::endl;
    std::cout << "Steps:\t\t" << max_steps << std::endl;
}

//veced data to save!
template<typename X>
void save_data(std::vector<X> veced_data, int index){
    std::string folder = "./output/" + inFileName;
    std::string out_name = folder + "/body" + std::to_string(index+1) + ".csv";
    std::ofstream outs(out_name, std::ios_base::app);
    outs << veced_data[0];
    for(int o = 1; o < veced_data.size(); ++o){
        outs << "\t" << veced_data[o];
    }
    outs << "\n";
    outs.close();
}


//probably remain unused
template<typename X>
void reset_mat(std::vector<std::vector<X>> mat){
    for(int i=0; i<mat.size(); ++i){
        std::vector<X> nuller(mat[i].size(),0);
        mat[i] = nuller;
    }
}

//updating distances! -NOT NEEDED,NOT USED,INDEXES OUT OF BOUND SOMEWHERE
//THIS COULD BE HANDY, BUT I DON'T SEE WHERE I GO OUT OF BOUNDS...
template<typename X> 
void updateDistances(std::vector<std::vector<X>> mat){
    std::vector<X> temp_dist(body_count*(body_count-1)/2,0);
    for(int i = 0; i < body_count-1; ++i){
        for(int j = i+1; j < body_count-1; ++j){
            std::vector<double> loc1(dim,0);
            std::vector<double> loc2(dim,0);
            for(int k=0; k < dim; k++){
                loc1[k] = mat[i][1+k];
                loc2[k] = mat[j][1+k];
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

//returns only one, but takes to... 3 body -> 6 calls
// the info carrier has to be used and l

template<typename X>
std::vector<X> derivative(const std::vector<X>& loc, int& index){
    double t = loc[0];  // time sat
    std::vector<X> f(1+2*dim); //set my deriv vec to zero initials
    f[0] = 1;

    for(int i = 0; i < dim; ++i){
        f[1+i] = loc[1+dim+i]; // copy vel
    }

    for(int i = 0; i < body_count; ++i){
        for(int j = 0; j < dim; j++){
            if(i != index){    
                //count acceleation that affcts this [index] body
                std::vector<X> r1(3),r2(3);
                r1[0] = loc[1]; r1[1] = loc[2]; r1[2] = loc[3];
                r2[0] = trv[i][1]; r2[1] = trv[i][2]; r2[2] = trv[i][3];
                X rSquare = abs_vec(r1-r2);
                X rCubed = rSquare * sqrt(rSquare);
                f[1+dim+j] = - G * masses[i] * (loc[1+j] - trv[i][1+j]) / rCubed;
            }
        }
    }
    return f;
}

void initSystem( ){
    std::string filename = path1 + inFileName + ".txt";
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
        trv_new = temp_trv;
        print_vector(masses);
        print_vec_set(trv);
        //print_vec_set(trv_new);

        std::cout << "Loading finished!" << std::endl;
        std::string folder = "./output/" + inFileName;
        _mkdir(folder.c_str());
    ;
        for(int o = 0; o < body_count; ++o){
            std::ofstream outs;
            std::string out_name = folder + "/body" + std::to_string(o+1) + ".csv";
            outs.open(out_name);
            outs << "#Does this work?\n";
            outs.close();
        }
    } else {
        std::cout << "Something went wrong while loading!\nStopping!" << std::endl;
    }
}

//after init, this will run and save it
void runSystem(){
    //we already saved starting pos
    double current_time = dt;
    do {
        for(int i = 0; i < body_count; ++i) {RK4(trv_new[i],dt,i);}
        for(int i = 0; i < body_count; ++i) save_data(trv[i],i);
        updateTRV();
        current_time += dt;
    } while (current_time < T);
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
        inFileName = "test";
        T = 1;
        dt = 1e-4;
        dim = 3;
        body_count = 3;
        std::string filename1 = path1 + inFileName;     
    }else if(argc = 2){
        inFileName = argv[1];
        std::cout << "3D simulation assumed! Errors may rise!" << std::endl;
        T = 1;
        dt = 1e-4;
        dim = 3;
        body_count = 3;

    } else if(argc = 3){
        inFileName = argv[1];
        T = atoi(argv[2]);
        dt = 1e-4;
        dim = 3;
        body_count = 3;
    } else if(argc = 4){
        inFileName = argv[1];
        T = atoi(argv[2]);
        dt = atof(argv[3]);
        dim = 3;
        body_count = 3;
    } else if(argc = 5){
        inFileName = argv[1];
        T = atoi(argv[2]);
        dt = atof(argv[3]);
        dim = atoi(argv[4]);
        body_count = 3;
    } else {
        inFileName = argv[1];
        T = atoi(argv[2]);
        dt = atof(argv[3]);
        dim = atoi(argv[4]);
        body_count = atoi(argv[5]);
    }
    max_steps = T/dt;
    print_infos();

    //file loading - init
    initSystem(); 
    runSystem();
    //std::cout << trv[1][6] << std::endl;
    std::cout << "Finished" << std::endl;
    return 0;
}
