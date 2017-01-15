#ifndef VECTOR2_H
#define VECTOR2_H

#include <Definitions.h>

struct Vector2 {

    float x,y;

    inline friend float operator*(const Vector2& u, const Vector2& v) {
        return dot(u, v);
    }

    inline friend float dot(const Vector2& u, const Vector2& v) {
        return u.x * v.x + u.y * v.y;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {

        os << "[" << v.x << ", " << v.y << "]";

        return os;
    }
};

#endif /*VECTOR2_H*/