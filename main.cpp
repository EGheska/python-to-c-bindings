#include <pybind11/pybind11.h>

namespace py = pybind11;

float some_fn(float fn1,float fn2){
    return fn1+fn2;
}

PYBIND11_MODULE(module_name, handle){
    handle.doc() = "This is the module docs.";
    handle.def("some_fn_python_name",&some_fn);
}