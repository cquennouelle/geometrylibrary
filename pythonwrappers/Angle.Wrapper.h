#include <boost/python.hpp>
#include "Angle.h"

using namespace boost::python;
using namespace Geometry;

void export_Angle()
{
    class_<Angle>("Angle")
            .def(init<Angle>())
//            .def("Rad", &Angle::Rad)//.staticmethod("Rad")
//            .def("RAD", &Angle::RAD, return_value_policy<manage_new_object>()).staticmethod("RAD")
            //.def("ModuloPI", &Angle::Modulo2PI)
            //            .def(str(self))
            //            .def(self + self)           // __add__
            //            .def(self - self)           // __sub__
            //.add_property("rad", &Angle::RAD, &Angle::Rad)
            ;
}
