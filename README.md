<h1>C++ to Python via Pybind11</h1>
This is an example of implementation of a Pybind11 library in python which allows us to invoke C++ functions, classes and methods in python. The 
In order to make it work
```console
cd build/
pip install pybind11
cmake .. -Dpybind11_DIR=${python3 -m pybind11 --cmakedir}
```
OR
```console
cmake .. -Dpybind11_DIR=$(python3 -m pybind11 --cmakedir)
```
And after all of this finally
```console
make
```
