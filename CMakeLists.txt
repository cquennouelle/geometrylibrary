cmake_minimum_required (VERSION 2.8)
project (GeometryProject)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

### Make Geometry lib
add_subdirectory("${CMAKE_SOURCE_DIR}/src/")

### Make unittests
add_subdirectory("${CMAKE_SOURCE_DIR}/utests/")

### Make Python wrapper
add_subdirectory("${CMAKE_SOURCE_DIR}/pythonwrappers/")
