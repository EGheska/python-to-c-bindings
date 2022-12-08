import build.calculator
from build.calculator import *
import build.dynamic_array


print(dir(build.calculator))
#Simple function
print(sum(1.1,2))
print(subs(3,2))
print(mult(3,2))
print(div(3,2))
#Clases
print("Class on")
m = CalculatorClass(5)
print(m.multiply(10))
print(m.multiply_list([1,3,10]))

#Class functions
print(build.calculator.div(2,0))

#Test for tuple
print(m.multiply_two_nr(10,100))

#Test dynamic array
print("Dynamic array")

arr = build.dynamic_array.DynamicArray()
arr.append(1)
arr.append(2)
arr.append(3)
print(arr.to_vector())


