#include <pybind11/pybind11.h>

namespace py = pybind11;
class Calculator{
    public: 

float sum(float fn1,float fn2){
    return fn1+fn2;
}
float subst(float fn1,float fn2){
    return fn1-fn2;
}
};

PYBIND11_MODULE(module_name, handle){
    handle.doc() = "This is the module docs.";
    handle.def("sum",[](float param1, float param2){return param1+param2;});
    handle.def("subs",[](float param1, float param2){return param1-param2;});
}