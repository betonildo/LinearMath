#ifndef MATRIX4_H
#define MATRIX4_H

#define DEBUG
#include <Definitions.h>
#include <Vector4.h>

class Matrix4 {

    union {
        float m_1d[16];
        float m_2d[4][4];
        __m128 m_rows[4];
        Vector4 m_vecrows[4];
    };

public:

    inline void clear() {
        memset(m_1d, 0, sizeof(Matrix4));
    }

    inline Vector4& operator[](int index) {
        ASSERT(index < 4, "matrix4 vector index out of bounds");
        return m_vecrows[index];
    }

    inline float& operator()(int rowIdx, int colIdx) {
        ASSERT(rowIdx < 4 && colIdx < 4, "matrix4 access out of bounds");

        return m_2d[rowIdx][colIdx];
    }

    inline friend Matrix4 operator*(const Matrix4& m1, const Matrix4& m2) {
        
        Matrix4 mr;

        mr.m_vecrows[0] = m1.m_vecrows[0] * m2;
        mr.m_vecrows[1] = m1.m_vecrows[1] * m2;
        mr.m_vecrows[2] = m1.m_vecrows[2] * m2;
        mr.m_vecrows[3] = m1.m_vecrows[3] * m2;

        return mr;
    }

    inline friend Vector4 operator*(const Vector4& u, const Matrix4& m) {
        
        Vector4 v;
        v._sse_var = mulVectorMatrixFinal(u._sse_var, m.m_rows);
        return v;
    }

    inline friend std::ostream& operator<<(std::ostream& os, const Matrix4& m) {
        
        os << m.m_vecrows[0] << "\n";
        os << m.m_vecrows[1] << "\n";
        os << m.m_vecrows[2] << "\n";
        os << m.m_vecrows[3] << "\n";

        return os;
    }
};

#endif /*MATRIX4_H*/