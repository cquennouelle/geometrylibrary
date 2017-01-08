cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(GeometryPython)

include_directories(/usr/include/python2.7)

# Create a library
file(GLOB GEOMETRY_WRAPPER_SOURCES *.cpp)
file(GLOB GEOMETRY_WRAPPER_HEADERS *.h)

find_package(Boost 1.45.0)
if(Boost_FOUND)
    set(Boost_USE_STATIC_LIBS   OFF)
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_STATIC_RUNTIME OFF)
    find_package(Boost 1.45.0 COMPONENTS
                    system
                    thread
                    python
                    REQUIRED)

    find_package(PythonLibs REQUIRED)
    include_directories(${PYTHON_INCLUDE_DIRS})
    link_directories(${PYTHON_LIBRARIES})
    link_directories(${Boost_LIBRARIES})

    ## Create a library
    include_directories(../src)
    add_library(GeometryPython SHARED
                            ${GEOMETRY_WRAPPER_HEADERS}
                            ${GEOMETRY_WRAPPER_SOURCES})
    target_link_libraries(GeometryPython
                            Geometry
                            ${PYTHON_LIBRARIES}
                            ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Unable to find correct Bost version.")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions("-Wall")
else()
  message(FATAL_ERROR "CMakeLists.txt has not been tested/written for your compiler.")
endif()
