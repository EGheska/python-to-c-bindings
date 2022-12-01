import build.calculator
from build.calculator import *

print(dir(build.calculator))

print(sum(1.1,2))
print(subs(3,2))
print(mult(3,2))
print(div(3,2))
print("Class on")
m = CalculatorClass(5)
print(m.multiply(10))
print(m.multiply_list(1,3,10))