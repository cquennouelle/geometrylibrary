
// Code found here:
// http://cprohm.de/article/wrapping-c-code-using-boost-python.html

// find the function pointer type of a lambda
// adapted from http://stackoverflow.com/a/7943765
template<typename T>
struct lambda_pointer_type
    : lambda_pointer_type<decltype(&T::operator())>
{

};

template<typename C, typename R, typename... Args>
struct lambda_pointer_type<R(C::*)(Args...) const>
{
    typedef R (*type)(Args...);
};

// return a function pointer for a no-capture lambda
template<typename F>
typename lambda_pointer_type<F>::type lambda_pointer(F f) {
    return f;
}

// minimal wrapper around boost::python::class_
template<typename WrappedType>
struct wrap_class : public boost::python::class_<WrappedType>
{
    typedef boost::python::class_<WrappedType> parent;

    template<typename... Args>
    wrap_class(Args... args)
    : parent(args...)
    {

    }

    template<typename... Args>
    wrap_class<WrappedType>& def(Args... args)
    {
        parent::def(args...);
        return *this;
    }

    template<typename F>
    wrap_class<WrappedType>& def_inline(const char* name, F impl)
    {
        parent::def(name, lambda_pointer(impl));
        return *this;
    }
};

