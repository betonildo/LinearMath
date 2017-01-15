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
    Quaternion(const Vector3& v, float s);
    Quaternion(const Vector4& v);
    Quaternion(const Quaternion& q);
    ~Quaternion();

    inline Matrix3& getMatrix() {
        
        float* m = m_rotation();
        float x = v.x;
        float y = v.y;
        float z = v.z;
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

    inline friend Quaternion& operator*(const Quaternion& p, const Quaternion& q) {
        
        Quaternion& pq = (Quaternion&)*(new Quaternion()); //creates a reference to heap
        Vector3 pv = p.v;
        Vector3 qv = q.v;
        float ps = p.s;
        float qs = q.s;
                
        std::cout << "pv = " << pv << LF;
        std::cout << "ps = " << ps << LF;

        std::cout << "qv = " << qv << LF;
        std::cout << "qs = " << qs << LF;

        Vector3 ps_t_qv = ps * qv;
        Vector3 qs_t_pv = qs * pv;
        Vector3 pv_t_qv = pv * qv;
        pq.v = ps_t_qv + qs_t_pv + pv_t_qv;
        pq.s = (ps * qs) - dot(pv, qv);

        std::cout << "ps_t_qv = " << ps_t_qv << LF;
        std::cout << "qs_t_pv = " << qs_t_pv << LF;        
        std::cout << "pq.v = " << pq.v << LF;
        std::cout << "pq.s = " << pq.s << LF;
        

        return pq;
    }

    inline Quaternion& operator=(const Quaternion& q) {
        
        v = q.v;
        s = q.s;

        return *this;
    }
};

#endif /*QUATERNION_H*/