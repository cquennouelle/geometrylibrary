cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Geometry_UT)

enable_testing()
find_package(GTest REQUIRED)
message(${GTEST_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})

# Create an application
link_directories("/opt/gtest/lib")
file(GLOB UNITTESTS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
ADD_EXECUTABLE(Geometry_UT	${UNITTESTS})
TARGET_LINK_LIBRARIES(Geometry_UT   	Geometry
                                        ${GTEST_BOTH_LIBRARIES}
                                        pthread)
add_test(AllTestsInFoo Geometry_UT)
