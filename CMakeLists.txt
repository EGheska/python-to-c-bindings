cmake_minimum_required(VERSION 3.20)
project(simple_pybind)

#set(pybind11_DIR /home/pc/Templates/AdvancedProgamming/venv/lib/python3.10/site-packages/pybind11/share/cmake/pybind11)
find_package(pybind11 REQUIRED)
pybind11_add_module(module_name main.cpp)
