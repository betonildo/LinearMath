#ifndef MATRIX4_H
#define MATRIX4_H

#define DEBUG
#include <Definitions.h>
#include <Debug.h>
#include <Vector4.h>

class Matrix4 {

    union {
        float m_1d[16];
        float m_2d[4][4];
        #ifdef USE_SSE
        __m128 m_rows[4];
        #endif
        Vector4 m_vecrows[4];
    };

public:

    inline Matrix4() {

    }

    inline Matrix4(float matrix[16]) {
        memcpy(m_1d, matrix, sizeof(float) * 16);
    }

    inline Matrix4(const Matrix4& m) {
        memcpy(this, &m, sizeof(Matrix4));
    }

    inline void turnIdentity() {

        clear();

        m_2d[0][0] = 1;
        m_2d[1][1] = 1;
        m_2d[2][2] = 1;
        m_2d[3][3] = 1;
    }

    inline void turnTransversal() {

        std::swap(m_2d[1][0], m_2d[0][1]);
        std::swap(m_2d[2][0], m_2d[0][2]);
        std::swap(m_2d[3][0], m_2d[0][3]);
        std::swap(m_2d[2][1], m_2d[1][2]);
        std::swap(m_2d[3][1], m_2d[1][3]);
        std::swap(m_2d[3][2], m_2d[2][3]);
    }

    inline void clear() {
        memset(m_1d, 0, sizeof(Matrix4));
    }

    inline float* operator[](int index) {
        ASSERT(index < 4, "matrix4 vector index out of bounds");
        return m_2d[index];
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

        #ifdef USE_SSE
            v._sse_var = mulVectorMatrixFinal(u._sse_var, m.m_rows);
        #else
            Vector4 vTemp0 = m.m_vecrows[0] * u.x;
            Vector4 vTemp1 = m.m_vecrows[1] * u.y;
            Vector4 vTemp2 = m.m_vecrows[2] * u.z;
            Vector4 vTemp3 = m.m_vecrows[3] * u.w;
            v = vTemp0 + vTemp1 + vTemp2 + vTemp3;
        #endif
        
        return v;
    }

    inline friend bool operator==(const Matrix4& m1, const Matrix4& m2) {
        return (m1.m_vecrows[0] == m2.m_vecrows[0] &&
                m1.m_vecrows[1] == m2.m_vecrows[1] &&
                m1.m_vecrows[2] == m2.m_vecrows[2] &&
                m1.m_vecrows[3] == m2.m_vecrows[3]);
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