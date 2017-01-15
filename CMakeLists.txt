cmake_minimum_required (VERSION 2.6)

project(LinearMath)

set(CMAKE_CXX_FLAGS " -std=c++11 ")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_BINARY_DIR}")

set(TRANSLATION_UNITS 
    main.cpp
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
    include/Definitions.h)

add_executable(LinearMath "${TRANSLATION_UNITS}" "${INCLUDE_UNITS}")