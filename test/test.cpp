#include <Matrix4.h>
#include "linearmath_local_definitions.h"
#include <string>


int main(int argc, char** argv) {

	Matrix4 m1 = Matrix4::orthoProjection(-1, 1, -1, 1, 1, 1000);

	std::cout << m1;

	Matrix4 m2 = Matrix4::lookAt(Vector3(0, 0, 0), Vector3(1, 0, 0), Vector3(0, 1, 0));

	std::cout << m2;

	return 0;
}