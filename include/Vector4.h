#ifndef VECTOR4_H
#define VECTOR4_H

#include <Definitions.h>
#include <Vector3.h>

struct Vector4 {
    
    union {
        struct {
            float x, y, z, w;
        };
        __m128 _sse_var;
    };
    

    inline operator Vector3&() {
        return *this;
    }

    inline Vector4& operator=(const Vector3& v) {

        #ifdef USE_SSE
            _sse_var = v._sse_var;
        #else
            x = v.x;
            y = v.y;
            z = v.z;
        #endif

        return *this;
    }

    inline Vector4& operator=(const Vector4& v) {
        
        #ifdef USE_SSE
            _sse_var = v._sse_var;
        #else
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
        #endif

        return *this;
    }

    inline friend Vector4 operator*(const Vector4& u, const __declspec(align(16)) float& f) {
        
        Vector4 v;

        #ifdef USE_SSE
            //__declspec(align(16)) float A[]={f, f, f, f};
            v._sse_var = _mm_set_ps(f, f, f, f);// _mm_load_ps(&A[0]);
            v._sse_var = _mm_mul_ps(v._sse_var, u._sse_var);
            
            
        #else
            v.x = u.x * f;
            v.y = u.y * f;
            v.z = u.z * f;
            v.w = u.w * f;
        #endif

        return v;
    }

    inline friend float operator*(const Vector4& u, const Vector4& v) {
        return dot(u, v);
    }

    inline friend float dot(const Vector4& u, const Vector4& v) {
        return u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Vector4& v) {

        os << "[" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";

        return os;
    }
};

#endif /*VECTOR4_H*/