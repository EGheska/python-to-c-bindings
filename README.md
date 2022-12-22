# C++ to Python via Pybind11

This is an example of implementation of a Pybind11 library in python which allows us to invoke C++ functions, classes and methods in python. 
#



Below you can find an examples of working C++ class, whose functional parts are awailable in the python.
## 1 Set up 
The first this  - must set up CMakeList.txt
To set up a ```CMakeLists.txt``` file for using pybind11 to create Python bindings for a C++ library, you can use the following template:
```
make_minimum_required(VERSION 3.20)

# Set the project name and specify the C++ language standard
project(<project_name>)

# Add the pybind11 module and set the pybind11_MODULE flag to create a Python module
find_package(pybind11 REQUIRED)

# Create the library target
add_library(<library_name> ${SOURCES} ${HEADERS})

# Create the Python module target, could be multiple targets
pybind11_add_module(<module_name> <main_binding_file>.cpp)

# Link the library to the Python module target
target_link_libraries(<module_name> PRIVATE <library_name>)

```
Replace ```<project_name>```, ```<library_name>```, and ```<module_name>``` with the desired names for your project, C++ library, and Python module, respectively. Replace
```<source_file1>.cpp```, ```<source_file2>.cpp```, etc. with the names of the source files for your library, and replace ```<header_file1>.h```, ```<header_file2>.h```, etc.
with the names of the header files for your library. Replace <main_binding_file>.cpp with the name of the main binding file that will contain the Python
wrapper functions for your C++ library.

This CMakeLists.txt file will build your C++ library and create a Python module that wraps the functions and classes in the library. To use the module in
Python, you will need to build the project and install the module using CMake and Python.







## 1.1 Set up
There is actually a few methods how to run this program. You can either run via terminal or using the `test.py` program, where everyrhing is implemented. 
After sucsessfull downloading the code and opening it in code redactor (IDE) you firsly need to download pybind11 library in case if you don't have it. But, beware, you cannot run `test.py` before you do the steps below

So, go for 
```console
cd build/
pip install pybind11
```

After installing, you can comile it with C++ compilator. Preferably uses CMake
```console
cmake .. -Dpybind11_DIR=$(python3 -m pybind11 --cmakedir)
```

And after all of this you can run the written binds for python.
```console
make
```
## 1.2 Writing the modules
To write the module to execute the program you first need to define the module
``` 
PYBIND11_MODULE(function_name, handler)
```
Where ```function_name``` is the name of the function you want to execute in python and the ```handler``` is the python object which allows us to iterate in the module, the name of the variable could be whatever you want it to be or you can just leave handle in order to makes it work.

After the definition we can write the instructions to the module what and how to do. The example instruction is
```
handle.def("sum",[](float param1, float param2){return param1+param2;});
```
Where ```handle``` is the python object which we passed in definition, ```.def``` is the standart python name of the function. In this function we're passing the name in this case ```"sum"```, empty array ```[]``` and the parameters. Also, we define what the module will return. In this case ```{return param1+param2;}```

## 2. Executing the program

For running the code, you have to install WSL (Windows subsystem for Linux) or if you are a Linux or MacOS user it is not nessesary sisce you can run your code in terminal.

### MacOS, Linux and Windows Subsystem
  
After a sucsessfull `make` the file, you can type `python3` in your terminal and start executing the functions

```python
>>> import build.calculator
>>> build.calculator.sum (1,2)
3
```
And you'll see the result of a computation in your python terminal.

### Run `test.py`
Steps above is not nessesary if you are running the program using `test.py` 


```console
$ python3 test.py
```

This python program has written test functions for the bindings, so you can test it and work on it.

## 3. What is included in the program?

This program has several functions written in C++. These functions behave as a simple calculator class (notice, that not all the functions belong to this class, since the program show the functionality of the library, and it is nessesary to show that the standalone functions works). By executing them you can perform an addition, subtraction, multiplication and division functions. Also, the other part of functionality is that the pybinds can handle the `dynamic_array.cpp` class, which implements the dynamic array

## 4. In case the program is not working

The most common issue is that the caches of CMake is old and you have to renew it.

Go for,

```console
cd build/
rm CMakeCache.txt
```

Now your caches are deleted, and you have to compile the program again in order to generate a new caches

```console
cd ..
## make sure that you are not in the build directory
make
```
 ## 5. Importance of Pybind11

Pybind11 is a library that allows developers to create Python bindings for C++ code. This can be useful in many scenarios, such as when a developer has existing C++ code that they want to make available to Python users, or when they want to take advantage of the performance of C++ while still using the convenience of the Python ecosystem.

One of the main advantages of using Pybind11 is that it allows developers to write Python bindings in a way that is clean, efficient, and easy to maintain. This is because Pybind11 provides a simple and intuitive interface that makes it easy to bind C++ functions and classes to Python. Additionally, Pybind11 generates the necessary Python C-extension code automatically, which can save developers a lot of time and effort.

Overall, Pybind11 is an important tool for developers who want to create Python bindings for their C++ code, and it can be very useful for optimizing the performance of Python programs.

## 6. Links and references:

- [realpython](https://realpython.com/python-bindings-overview/)
- [Github::pybind11](https://github.com/pybind/pybind11)
- [Pybind](https://pybind11.readthedocs.io/en/stable/basics.html)
- [Github cmake_example](https://github.com/pybind/cmake_example)
