cmake_minimum_required (VERSION 2.6)

project(LinearMath)

set(CMAKE_CXX_FLAGS " -std=c++11 ")
option (COMPILE_TESTS "Compile all main.cpp files to test subprojects" OFF)
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_BINARY_DIR}")

file(GLOB TRANSLATION_UNITS src/*.cpp)
file(GLOB INCLUDE_UNITS include/*.h)

# Required on Unix OS family to be able to be linked into shared libraries.
#set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

#if (COMPILE_TESTS)
    set(TRANSLATION_UNITS "${TRANSLATION_UNITS}" main.cpp)
    add_executable(LinearMath "${TRANSLATION_UNITS}" "${INCLUDE_UNITS}")
#endif(COMPILE_TESTS)

target_link_libraries(${PROJECT_NAME})

# Expose B's public includes (including Boost transitively) to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)


