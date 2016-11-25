cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Geometry_wrapper)

include_directories(/usr/include/python2.7)

# Create a library
file(GLOB GEOMETRY_WRAPPER_SOURCES *.cpp)
file(GLOB GEOMETRY_WRAPPER_HEADERS *.h)

add_library(Geometry_wrapper 	${GEOMETRY_WRAPPER_SOURCES}
				${GEOMETRY_WRAPPER_HEADERS})
