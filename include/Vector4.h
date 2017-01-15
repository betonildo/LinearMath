#ifndef VECTOR4_H
#define VECTOR4_H

#include <Definitions.h>
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

    inline friend std::ostream& operator<<(std::ostream& os, const Vector4& v) {

        os << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";

        return os;
    }
};

#endif /*VECTOR4_H*/