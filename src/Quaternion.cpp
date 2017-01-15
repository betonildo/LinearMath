#include <Quaternion.h>

Quaternion::Quaternion() {

}

Quaternion::Quaternion(float x, float y, float z, float w) {
    v = Vector3(x, y, z);
    s = w;
}

Quaternion::Quaternion(const Vector3& v, float s) {
    this->v = v;
    this->s = s;
}

Quaternion::Quaternion(const Vector4& v) {
    this->v = (Vector3)(Vector3&)v;
    s = v.w;
}

Quaternion::Quaternion(const Quaternion& q) {
    (*this) = q;
}


Quaternion::~Quaternion() {
    
}