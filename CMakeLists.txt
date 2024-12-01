cmake_minimum_required(VERSION 3.25.1)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-g -Wall -Wextra -Wpedantic -Wl,--stack,16777216)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(raytracer raytracer.cc
        utils/math/math.cc
        geometry/geometry.cc
        camera/camera.cc
        utils/color/color.h
        utils/color/color.cc)

enable_testing()
add_executable(math_test utils/math/math_test.cc utils/math/math.cc)
target_link_libraries(math_test gtest gtest_main)

add_executable(geometry_test geometry/geometry_test.cc geometry/geometry.cc utils/math/math.cc
        Scene/Scene.cc
        Scene/Scene.h
        Scene/Light/Light.cc
        Scene/Light/Light.h)
target_link_libraries(geometry_test gtest gtest_main)

