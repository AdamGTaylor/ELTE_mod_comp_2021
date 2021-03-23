#pragma once

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
    std::ostream& operator<<(std::ostream& o, Vector2D const& v){
        o << "(" << v.x << ";" << v.y << ")";
        return o;
    }
    //setting up values... i heavily dislike to do this way, but we gonna change the values anyway
    std::istream& operator>>(std::istream& i, Vector2D& v){
        i >> v.x;
        i >> v.y;
    }
    Vector2D<T>& operator+=(Vector2D<T> const& v){
        x += v.x; y += v.y;
        return *this;
    }
    Vector2D<T>& operator-=(Vector2D<T> const& v){
        x -= v.x; y -= v.y;
        return *this;
    }
    Vector2D<T> operator+( Vector2D<T> const& a, Vector2D<T> const& b){
        return Vector2D<T>{a.x + b.x, a.y + b.y};
    }
    Vector2D<T> operator-( Vector2D<T> const& a, Vector2D<T> const& b){
        return Vector2D<T>{a.x - b.x, a.y - b.y};
    }
    //vec*T, T*vec -> T*vec
    //vec/T
    //vec*vec -> skal
    //dot -> vec
    
};