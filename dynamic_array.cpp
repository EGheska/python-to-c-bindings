#include <iostream>
#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

template<typename T>

class DynamicArray{
    public:
    DynamicArray(){
        data = std::vector<T>();
    }
    void append(const T&item){
        data.push_back(item);
    }
    std::vector<T> to_vector() const{
        return data;
    }
    size_t size() const{
        return data.size();
    }
    private:
    std::vector<T> data;
};

PYBIND11_MODULE(dynamic_array, m)
{
    py::class_<DynamicArray<py::object>>(m, "dynamicArray")
        .def(py::init<>())
        .def("append", &DynamicArray<py::object>::append)
        .def("to_vector", &DynamicArray<py::object>::to_vector)
        .def("size", &DynamicArray<py::object>::size);
}

