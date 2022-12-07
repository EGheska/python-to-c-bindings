# C++ to Python via Pybind11

This is an example of implementation of a Pybind11 library in python which allows us to invoke C++ functions, classes and methods in python. 
#
Below you can find an examples of working C++ class, whose functional parts are awailable in the python.
#
## 1. Set up
 There is actually a few methods how to run this program. You can either run via terminal or using the `test.py` program, where everyrhing is implemented. 
After sucsessfull downloading the code and opening it in code redactor (IDE) you firsly need to download pybind11 library in case if you don't have it.

So, go for 
```console
cd build/
pip install pybind11
```

After installing, you can comile it with C++ compilator. Preferably uses CMake
```
cmake .. -Dpybind11_DIR=${python3 -m pybind11 --cmakedir}
```
OR
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
$ python test.py
```
