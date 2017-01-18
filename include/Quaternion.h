#ifndef QUATERNION_H
#define QUATERNION_H

#include <Definitions.h>
#include <Matrix3.h>
#include <Vector4.h>
#include <Vector3.h>

class Quaternion {

private:
    Matrix3 m_rotation;

public:

    Vector3 v;
    float s;   

    Quaternion();
    Quaternion(float x, float y, float z, float w);
    Quaternion(Vector3& v, float s);
    Quaternion(Vector4& v);
    Quaternion(const Quaternion& q);
    ~Quaternion();

    inline Matrix3& getMatrix() {
        
        float* m = m_rotation();
        Vector3 normalized = v.normalize();
        float x = normalized.x;
        float y = normalized.y;
        float z = normalized.z;
        float w = s;
        float x_squared = x * x;
        float y_squared = y * y;
        float z_squared = z * z;

        float y_T_z_MINUS_x_T_w = y * z - x * w;
        // row 1
        m[0] = 1 - 2 * (y_squared + z_squared);
        m[1] = 2 * (x * y + z * w);
        m[2] = 2 * (x * z - y * w);

        // row 2
        m[3] = 2 * (x * y - z * w);
        m[4] = 1 - 2 * (x_squared + z_squared);
        m[5] = 2 * y_T_z_MINUS_x_T_w;

        // row 3
        m[6] = 2 * (x * z + y * w);
        m[7] = 2 * y_T_z_MINUS_x_T_w;
        m[8] = 1 - 2 * (x_squared + y_squared);

        return m_rotation;
    }

    inline friend Quaternion operator*(const Quaternion& p, const Quaternion& q) {
        
        Quaternion pq;

        Vector3 pv = p.v;
        Vector3 qv = q.v;

        float ps = p.s;
        float qs = q.s;

        pq.v = (ps * qv) + (qs * pv) + (pv * qv);
        pq.s = (ps * qs) - dot(pv, qv);

        return pq;
    }

    inline Quaternion& operator=(const Quaternion& q) {
        
        v = q.v;
        s = q.s;

        return *this;
    }
};

#endif /*QUATERNION_H*/