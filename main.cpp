#include <pybind11/pybind11.h>
#include <vector>
#include <pybind11/stl.h>

namespace py = pybind11;
class Calculator{
float multiplier;
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
Calculator(float multiplier_) : multiplier(multiplier_){};
float multiply(float input){
    return multiplier*input;
}
std::vector<float>multiply_list(std::vector <float> items){
    for(auto i = 0; i < items.size(); i++){
        items[i] = multiply(items.at(i));
    }
    return items;
}
};



PYBIND11_MODULE(calculator, handle){
    handle.def("sum",[](float param1, float param2){return param1+param2;});
    handle.def("subs",[](float param1, float param2){return param1-param2;});
    handle.def("mult",[](float param1,float param2){return param1*param2;});
    handle.def("div",[](float param1,float param2){return param1/param2;});
    py::class_<Calculator>(
        handle, "CalculatorClass"
    )
    .def(py::init<float>())
    .def("multiply",&Calculator::multiply)
    .def("multiply_list",&Calculator::multiply_list)
    ;
}


