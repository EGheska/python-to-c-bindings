# python-to-c-bindings
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
