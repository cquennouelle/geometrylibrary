#include "Angle.Wrapper.h"

//const std::string hello() {
//    return std::string("hello, zoo");
//}
//const std::string hello(
//        std::string const & you) {
//    return std::string("hello, " + you);
//}

//const std::string  (*hello_)() = &hello;
//const std::string  (*hello_you)(std::string const &) = &hello;

//BOOST_PYTHON_FUNCTION_OVERLOADS(hello_overloads, hello, 0, 1)

BOOST_PYTHON_MODULE(libGeometryPython)
{
    // An established convention for using boost.python.
    using namespace boost::python;

    // Expose the function hello().
//    def("hello", hello_);
//    def("hello", hello_you);
//    //def("hello", (const std::string(std::string const &))0, hello_overloads());

    export_Angle();
    //export_testWrapper();
}
