#include "Angle.Wrapper.h"

BOOST_PYTHON_MODULE(libGeometryPython)
{
    // An established convention for using boost.python.
    using namespace boost::python;

    export_Angle();
}
