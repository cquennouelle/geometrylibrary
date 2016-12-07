cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Geometry_UT)

find_package(GTest REQUIRED)
if(GTEST_FOUND)
    #message(${GTEST_INCLUDE_DIRS})
    #message(${GTEST_BOTH_LIBRARIES})
    include_directories(${GTEST_INCLUDE_DIRS})

    # Create an application
    file(GLOB UNITTESTS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
    ADD_EXECUTABLE(Geometry_UT	${UNITTESTS})
    TARGET_LINK_LIBRARIES(Geometry_UT   	Geometry
                                            ${GTEST_BOTH_LIBRARIES}
                                            pthread)
else()
    message("GTest NOT found.")
endif()
