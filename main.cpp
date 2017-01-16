#include <Definitions.h>
#include <Quaternion.h>
#include <Matrix3.h>
#include <Vector2.h>
#include <Vector3.h>
#include <Vector4.h>

#define DEBUG
#include <Debug.h>

void testVector2();
void testVector3();
void testVector4();

int main(int argc, char** argv) {

    
    Quaternion p(-1, -1, -1, PI);
    Quaternion q(1, 1, 1, -PI);
    Quaternion pq = p * q;

    Matrix3 m3 = pq.getMatrix();
    std::cout << m3;
    
    testVector2();

    return 0;
}

void testVector2() {
    Vector2 u, v;

    u.x = 1;
    u.y = 0;

    v.x = 0;
    v.y = 1;

    ASSERT(dot(u, v) == 0, "dot != 0");
}

void testVector3() {
    Vector3 u, v;

    u.x = 1;
    u.y = 1;
    u.z = 1;

    v.x = -1;
    v.y = -1;
    v.z = -1;

    ASSERT(dot(u, v) == -3, "dot != -3");
}

void testVector4() {

}