cmake_minimum_required(VERSION 3.20)
project(simple_pybind)

#set(pybind11_DIR /home/pc/Templates/AdvancedProgamming/venv/lib/python3.10/site-packages/pybind11/share/cmake/pybind11)

find_package(pybind11 CONFIG)
pybind11_add_module(calculator main.cpp)
pybind11_add_module(dynamic_array dynamic_array.cpp)
pybind11_add_module(linked_list linkedlist.cpp)
