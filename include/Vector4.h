#ifndef VECTOR4_H
#define VECTOR4_H

#include <Vector3.h>

struct Vector4 {

    float x, y, z, w;

    inline operator Vector3&() {
        return *this;
    }

    inline Vector4& operator=(const Vector3& v) {

        x = v.x;
        y = v.y;
        z = v.z;

        return *this;
    }
};

#endif /*VECTOR4_H*/