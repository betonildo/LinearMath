#include <Matrix4.h>
#include "linearmath_local_definitions.h"
#include <string>


int main(int argc, char** argv) {

	Matrix4 m1 = Matrix4::orthoProjection(-1, 1, -1, 1, 1, 1000);

	std::cout << m1;

	return 0;
}