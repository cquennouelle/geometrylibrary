# geometrylibrary
[![Build Status](https://travis-ci.org/cquennouelle/geometrylibrary.svg?branch=master)](https://travis-ci.org/cquennouelle/geometrylibrary)
Objectives
==========

Pet project to avoid reinventing the wheel on my side and to implement a geometric library nicely designed (closer to the mathematical concepts).

- src: contains source code
- utests: contains tests
- pythonwrappers: contains code for using the c++ lib with python

Installation
============
Requires Boost for Python
Requires GTest for unittests

Clone repository

	$ git clone https://github.com/cquennouelle/geometrylibrary.git

Create build directory and build source code:
	
	$ cd geometrylibrary
	
	$ mkdir build
	
	$ cd build
	
	$ cmake ..
	
	$ make

Launch tests
	
	$ make test
	
or

	$ utests/Geometry_UT

