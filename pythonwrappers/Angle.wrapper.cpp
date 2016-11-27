#include <boost/python.hpp>

char const* greet()
{
   return "hello, world";
}

BOOST_PYTHON_MODULE(geometry_ext)
{
    using namespace boost::python;
    def("greet", greet);
}
