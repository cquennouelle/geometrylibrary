cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Geometry)

# Create a library
file(GLOB GEOMETRY_SOURCES *.cpp)
file(GLOB GEOMETRY_HEADERS *.h)

add_library(Geometry 	SHARED
                        ${GEOMETRY_SOURCES}
			${GEOMETRY_HEADERS})

#target_link_libraries(Geometry   ${PCL_LIBRARIES})
