# -*- coding: utf-8 -*-
"""
Created on Sun Jan  8 20:50:38 2017

@author: localuser
"""
from __future__ import absolute_import
import os
buildDir = "/home/localuser/geometrylibrary/build/pythonwrappers"
#print(os.getcwd())
os.chdir(buildDir)
#print(os.getcwd())
#print(os.listdir(os.getcwd()))
#print(sys.path)

from libGeometryPython import *

if __name__ == '__main__':
    #import libGeometryPython
    a = Angle()
    b = a.Modulo2PI(15.0)
    b+=a
    c = Angle.RAD(2.0)
    d = Angle.DEG(2.0)
    a += c
    a += d
    b = a
    print(a.Rad())
    print(a==c)
    print(a==b)