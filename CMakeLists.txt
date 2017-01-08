cmake_minimum_required (VERSION 2.8)
project (GeometryProject)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_CXX_STANDARD 11)

### Make Geometry lib
add_subdirectory("${CMAKE_SOURCE_DIR}/src/")

### Make unittests
enable_testing(true)
add_subdirectory("${CMAKE_SOURCE_DIR}/utests/")
add_test(test utests/Geometry_UT)

### Make Python wrapper
add_subdirectory("${CMAKE_SOURCE_DIR}/pythonwrappers/")
