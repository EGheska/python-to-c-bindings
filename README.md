# C++ to Python via Pybind11

This is an example of implementation of a Pybind11 library in python which allows us to invoke C++ functions, classes and methods in python. 
#
Below you can find an examples of working C++ class, whose functional parts are awailable in the python.
#
## 1. Set up
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


## 2. Executing the program

For running the code, you have to install WSL (Windows subsystem for Linux) or if you are a Linux or MacOS user it is not nessesary sisce you can run your code in terminal.

### MacOS, Linux and Windows Subsystem
  
After a sucsessfull `make` the file, you can type `python3` in your terminal and start executing the functions

```python
>>> import calculator
>>> calculator.add(1,2)
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
 
