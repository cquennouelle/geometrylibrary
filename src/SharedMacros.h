
#define SAFE_DELETE(p) if(p!=NULL) { delete p; p=NULL; }

/*
//#define BASIC_METHOD_HEADER_FOR_WRAPPER_DOUBLE(T)\
//public:\
//    (#T)();\
//    (#T)(double const val);\
//    virtual ~(#T)();\
//private:\
//    double m_value;

//#define BASIC_METHOD_BODY_FOR_WRAPPER_DOUBLE(T) \
//    (#T)::(#T)():m_value(0.0) {}\
//    \
//    (#T)::(#T)(double const value):m_value(value) {}\
//    \
//    (#T)::~(#T)() {}\
*/

