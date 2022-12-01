import build.calculator
from build.calculator import *

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
