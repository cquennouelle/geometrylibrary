#include <boost/python.hpp>
//#include "wrapper_class.h"
#include "Angle.h"

//Geometry::Angle (*RAD_)(double const) = &Geometry::RAD;

void export_Angle()
{
    using namespace boost::python;
    using namespace Geometry;

//    def("RAD", &RAD_, return_value_policy<manage_new_object>());

    //wrap_class<Angle>("Angle", init<>())
    class_<Angle>("Angle", init<>())
            .def(init<Angle const &>())
            .def("Rad", &Angle::Rad)
            .def("Deg", &Angle::Deg)
            .def("Deg100th", &Angle::Deg100th)
            .def("EPSILON", &Angle::EPSILON).staticmethod("EPSILON")
 //           .def(self=self)
            .def(self==self)
            .def("RAD", &Angle::RAD).staticmethod("RAD")
            .def("DEG", &Angle::DEG).staticmethod("DEG")
            .def("DEG100th", &Angle::DEG100th).staticmethod("DEG100th")
            .def(self+=self)           // __iadd__
            .def(self-=self)           // __iadd__
//            .def(self*=double)           // __iadd__
//            .def(self+self)           // __add__
//            .def(self-self)           // __sub__
            .def("Modulo2PI", &Angle::Modulo2PI)
//            .def_inline("__repr__", [](const Angle & self)-> std::string {
//                return "Angle(" + boost::lexical_cast< std::string >(self.Rad()) + " rad)";
//                });
//    str(self))
//            .add_property("rad", &Angle::RAD, &Angle::Rad)
            ;
}

class TestWrapper
{
public:
    TestWrapper():m_name("default") {}
    TestWrapper(std::string const & name):m_name(name) {}
    TestWrapper(TestWrapper const & a):m_name(a.m_name) {}

    TestWrapper & operator+=(TestWrapper const & a);

    std::string getName() const { return m_name; }
    void setName(std::string const & name) { m_name = name; }

    bool const operator==(TestWrapper const & t2) const;

    static TestWrapper * NewInstance() { return new TestWrapper(); }

private:
    std::string m_name;
};

TestWrapper &TestWrapper::operator+=(const TestWrapper &a)
{
    m_name += a.getName();
    return *this;
}

const bool TestWrapper::operator==(const TestWrapper &t2) const
{
    return m_name == t2.getName();
}

TestWrapper operator+(TestWrapper const & t1, TestWrapper const & t2)
{
    return TestWrapper(t1)+=t2;
}

void export_testWrapper()
{
    using namespace boost::python;
    class_<TestWrapper>("TestWrapper", init<std::string const &>())
            .def(init<>())
            .def("Name", &TestWrapper::getName)
            .def(self==self) // __eq__
            .def(self+self) //__add__
            .def(self+=self) //__iadd__
            .add_property("name", &TestWrapper::getName, &TestWrapper::setName)
            .def("NewInstance", &TestWrapper::NewInstance, return_value_policy<manage_new_object>())
            .staticmethod("NewInstance")
            ;
}


