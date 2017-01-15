#include <Definitions.h>
#include <Quaternion.h>
#include <Matrix3.h>
#include <Vector3.h>
#include <Vector4.h>

int main(int argc, char** argv) {

    
    Quaternion p(-1, -1, -1, PI);
    Quaternion q(1, 1, 1, -PI);
    Quaternion pq = p * q;

    Matrix3 m3 = pq.getMatrix();

    printf("[%f, %f, %f, %f]\n", pq.v.x, pq.v.y, pq.v.z, pq.s);
    std::cout << m3;
    
    return 0;
}