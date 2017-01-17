cmake_minimum_required (VERSION 2.6)

project(LinearMath)

set(CMAKE_CXX_FLAGS " -std=c++11 ")
option (COMPILE_TESTS "Compile all main.cpp files to test subprojects" OFF)
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_BINARY_DIR}")

set(TRANSLATION_UNITS 
    src/Quaternion.cpp
    src/Matrix3.cpp
    src/Vector2.cpp
    src/Vector3.cpp
    src/Vector4.cpp)

set(INCLUDE_UNITS 
    include/Quaternion.h 
    include/Matrix3.h
    include/Vector2.h
    include/Vector3.h
    include/Vector4.h
    external/Definitions/Definitions.h)

if (COMPILE_TESTS)
    set(TRANSLATION_UNITS "${TRANSLATION_UNITS}" main.cpp)
endif(COMPILE_TESTS)


add_executable(LinearMath "${TRANSLATION_UNITS}" "${INCLUDE_UNITS}")