#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
#include <ostream>
#include <istream>
#include <math.h>

#define PI 3.14159265

template<typename T>
struct Vector2D
{   
    //I need to set them up! OKEY, USING OPERATORS ARE NOT SAVE OPTIONS FOR SETTING UP VALUES IN A STRUCT
    //WHAT'S THE POINT HAVING VISIBILITY (PRIVATE, PUBLIC, PROTECTED) THAN?
    T x,y;
    
    Vector2D( T const& a, T const& b){
        x = a;
        y = b;
    }
    //this way the values inside a struct can be private! not gonna use this...
    void set_x( T const& a){
        x = a;
    }
    void set_y( T const& b){
        y = b;
    }
    //printing, very handy!
    friend std::ostream& operator<<(std::ostream& o, Vector2D const& v){
        o << "(" << v.x << ";" << v.y << ")";
        return o;
    }
    //setting up values... i heavily dislike to do this way, but we gonna change the values anyway
    friend std::istream& operator>>(std::istream& i, Vector2D& v){
        i >> v.x;
        i >> v.y;
        return i;
    }
    Vector2D<T>& operator+=(Vector2D<T> const& v){
        x += v.x; y += v.y;
        return *this;
    }
    Vector2D<T>& operator-=(Vector2D<T> const& v){
        x -= v.x; y -= v.y;
        return *this;
    }
    Vector2D<T> norm(){
        return Vector2D<T>{ x / sqrt(x*x + y*y), y / sqrt(x*x + y*y)};
    }
};

template<typename T>
Vector2D<T>& operator+( Vector2D<T> const& v, Vector2D<T> const& w){
    return Vector2D<T>{v.x + w.x, v.y + w.y};
}

template<typename T>
Vector2D<T>& operator-( Vector2D<T> const& v, Vector2D<T> const& w){
    return Vector2D<T>{v.x - w.x, v.y - w.y};
}

//vec*T, T*vec -> T*vec
template<typename T>
Vector2D<T>& operator*(Vector2D<T> const& v, T const& a){
   return Vector2D<T>{a * v.x, a * v.y};
}

template<typename T>
Vector2D<T>& operator*(T const& a, Vector2D<T> const& v){
    return Vector2D<T>{a * v.x, a * v.y};
}

//vec/T
template<typename T>
Vector2D<T>& operator/(Vector2D<T> const& v, T const& a){
    return Vector2D<T>{v.x / a, v.y / a};
}

//vec*vec -> skal
template<typename T>
T skal(Vector2D<T> const& v, Vector2D<T> const& w){
    return (v.x * w.x + v.y * w.y);
}
//dot -> vec (elementwise multiplication.)
template<typename T>
Vector2D<T> dot(Vector2D<T> const& v, Vector2D<T> const& w){
    return Vector2D<T>{v.x * w.x, v.y * w.y};
}
    //coss multiplication? -> leads to scalars in 2D
    //diadic? -> out of scope, higher tensor

//rotation!
template<typename T>
Vector2D<T> rotate(T const& arc, Vector2D<T> const& v){
    double rad = arc * PI / 180; //this is bond to be double or float... int doesnt like this
    return Vector2D<T>{ (cos(rad) - sin(rad))*v.x, (cos(rad) + sin(rad))*v.y  };
}
//projection!

#endif