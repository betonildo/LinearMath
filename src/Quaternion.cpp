#include <Quaternion.h>

Quaternion::Quaternion() {

}

Quaternion::Quaternion(float x, float y, float z, float w) {
    v = Vector3(x, y, z).normalize();
    s = w;
}

Quaternion::Quaternion(Vector3& v, float s) {
    this->v = v.normalize();
    this->s = s;
}

Quaternion::Quaternion(Vector4& v) {
    this->v = ((Vector3)(Vector3&)v).normalize();
    s = v.w;
}

Quaternion::Quaternion(const Quaternion& q) {
    (*this) = q;
}


Quaternion::~Quaternion() {
    
}