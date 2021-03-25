#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
#include <ostream>
#include <istream>

template<typename T>
struct Vector2D
{   
    //I need to set them up! OKEY, USING OPERATORS ARE NOT SAVE OPTIONS FOR SETTING UP VALUES IN A STRUCT
    //WHAT'S THE POINT HAVING VISIBILITY (PRIVATE, PUBLIC, PROTECTED) THAN?
    T x,y;
    /*
    Vector2D( T const& a, T const& b){
        x = a;
        y = b;
    }*/
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

    
};

template<typename T>
Vector2D<T>& operator+( Vector2D<T> const& a, Vector2D<T> const& b){
    return Vector2D<T>{a.x + b.x, a.y + b.y};
}

template<typename T>
Vector2D<T>& operator-( Vector2D<T> const& a, Vector2D<T> const& b){
    return Vector2D<T>{a.x - b.x, a.y - b.y};
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
    //vec*vec -> skal
    //dot -> vec (elementwise multiplication.)
    //coss multiplication? -> leads to scalars in 2D
    //diadic? -> out of scope, higher tensor
    //rotation!
    //projection!
    //eigenvector or nomalisation

#endif