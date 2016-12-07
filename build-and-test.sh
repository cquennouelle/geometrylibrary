#!/bin/bash

mkdir build
cd build
cmake .. && make && utests/Geometry_UT


