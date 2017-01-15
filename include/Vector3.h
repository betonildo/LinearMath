#ifndef VECTOR3_H
#define VECTOR3_H

#include <Definitions.h>

struct Vector3 {

    float x, y, z;

    Vector3();
    Vector3(float x, float y, float z);
    Vector3(const Vector3& v);
    
    inline friend Vector3& operator*(const Vector3& u, const Vector3& v) {
        return cross(u, v);
    }

    inline friend Vector3& cross(const Vector3& u, const Vector3& v) {
        
        Vector3& r = (Vector3&)*(new Vector3());

        r.x = u.y * v.z - u.z * v.y;
        r.y = u.x * v.z - u.z * v.x;
        r.z = u.x * v.y - u.y * v.x;

        return r;
    }

    inline friend float dot(const Vector3& u, const Vector3& v) {
        return u.x * v.x + u.y * v.y + u.z * v.z;
    }

    inline friend Vector3& operator*(const Vector3& u, const float& f) {
        
        Vector3& r = (Vector3&)*(new Vector3());
        
        r.x = u.x * f;
        r.y = u.y * f;
        r.z = u.z * f;
        
        return r;
    }

    inline friend Vector3& operator*( const float& f, const Vector3& u) {
        
        Vector3& r = (Vector3&)*(new Vector3());
        
        r.x = u.x * f;
        r.y = u.y * f;
        r.z = u.z * f;
        
        return r;
    }

    inline friend Vector3& operator+(const Vector3& u, const Vector3& v) {
        
        Vector3& r = (Vector3&)*(new Vector3());
        
        r.x = u.x + v.x;
        r.y = u.y + v.y;
        r.z = u.z + v.z;
        
        return r;
    }

    inline Vector3& operator=(const Vector3& v) {

        x = v.x;
        y = v.y;
        z = v.z;
        
        return *this;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return os;
    };
};

#endif /*VECTOR3_H*/