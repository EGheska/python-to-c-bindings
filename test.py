import build.calculator
from build.calculator import *
import build.dynamic_array
import build.linked_list

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

arr = build.dynamic_array.dynamicArray()
arr.append(1)
arr.append(2)
arr.append(3)
arr.append("Hello")
arr.append("World")
print(arr.to_vector())

#Test for LinkedList

print("Linked list")


ll = build.linked_list.LinkedList()

print("Linked list insert front")
ll.insert_front(1)
ll.insert_front(2)
ll.insert_front(3)
print(ll.to_vector())
print("Linked list insert back")
ll.insert_back(4)
ll.insert_back(5)
ll.insert_back(6)
print(ll.to_vector())
print("Linked list insert after")
ll.insert_after(1,7)
ll.insert_after(2,8)
ll.insert_after(3,9)
print(ll.to_vector())
print("Linked list remove 1,2,3")
ll.remove(1)
ll.remove(2)
ll.remove(3)

print(ll.to_vector())


