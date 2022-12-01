#include <pybind11/pybind11.h>

namespace py = pybind11;
class Calculator{
    float sum;
    float subs;
    float mult;
    float div;

    public: 

float sum(float param1,float param2){
    return param1+param2;
}
float subs(float param1,float param2){
    return param1-param2;
}
float mult(float param1, float param2){
    return param1*param2;
}
float div(float param1, float param2){
    return param1/param2;
}
};



PYBIND11_MODULE(calculator, handle){
    handle.def("sum",[](float param1, float param2){return param1+param2;});
    handle.def("subs",[](float param1, float param2){return param1-param2;});
    handle.def("mult",[](float param1,float param2){return param1*param2;});
    handle.def("div",[](float param1,float param2){return param1/param2;});
    py::class_<Calculator>(
        handle, "CalculatorClass"
    );
}


