#include <boost/python.hpp>
#include "Angle.h"

std::string angle_str(Geometry::Angle const & angle)
{
    std::stringstream s;
    s << angle.Deg() << " deg";
    return s.str();
}

std::string angle_repr(Geometry::Angle const & angle)
{
    std::stringstream s;
    s << "Angle (" << angle.Rad() << " rad)";
    return s.str();
}

void export_Angle()
{
    using namespace boost::python;
    using namespace Geometry;

    class_<Angle>("Angle", init<>())
            .def(init<Angle const &>())
            .def("Rad", &Angle::Rad)
            .def("Deg", &Angle::Deg)
            .def("Deg100th", &Angle::Deg100th)
            .def("EPSILON", &Angle::EPSILON).staticmethod("EPSILON")
            .def(self==self)
            .def("RAD", &Angle::RAD).staticmethod("RAD")
            .def("DEG", &Angle::DEG).staticmethod("DEG")
            .def("DEG100th", &Angle::DEG100th).staticmethod("DEG100th")
            .def(self+=self)
            .def(self-=self)
            .def(self+self)
            .def(self*=double())
            .def(self/=double())
//            .def(self+self)           // __add__
//            .def(self-self)           // __sub__
            .def("Modulo2PI", &Angle::Modulo2PI)
            .def("__str__", &angle_str)
            .def("__repr__", &angle_repr);
            //.add_property("rad", &Angle::RAD, &Angle::Rad)
            ;

    def("RAD", &RAD);
    def("DEG", &DEG);
    def("DEG100th", &DEG100th);
}
