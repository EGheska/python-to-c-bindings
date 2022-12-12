
import unittest
import build.calculator
from build.calculator import *
import build.dynamic_array
import build.linked_list


class TestCalculator(unittest.TestCase):
    def test_sum(self):
        self.assertEqual(sum(1.1,2), 3.1)
    def test_subs(self):
        self.assertEqual(subs(3,2), 1)
    def test_mult(self):
        self.assertEqual(mult(3,2), 6)
    def test_div(self):
        self.assertEqual(div(3,2), 1.5)
    def test_div_by_zero(self):
        self.assertEqual(div(3,0), )
    def test_multiply_class(self):
        m = CalculatorClass(5)
        self.assertEqual(m.multiply(10), 50)
    def test_multiply_list(self):
        m = CalculatorClass(5)
        self.assertEqual(m.multiply_list([1,3,10]), ([5,15,50]))
    def test_multiply_two_nr(self):
        m = CalculatorClass(5)
        self.assertEqual(m.multiply_two_nr(10,100), ([50.0,500.0]))
    def test_dynamic_array(self):
        arr = build.dynamic_array.dynamicArray()
        arr.append(1)
        arr.append(2)
        arr.append(3)
        arr.append("Hello")
        arr.append("World")
        self.assertEqual(arr.to_vector(), [1,2,3,"Hello","World"])
    def test_linked_list(self):
        ll = build.linked_list.LinkedList()
        ll.insert_front(1)
        ll.insert_front(2)
        ll.insert_front(3)
        self.assertEqual(ll.to_vector(), [3,2,1])
        ll.insert_back(4)
        ll.insert_back(5)
        ll.insert_back(6)
        self.assertEqual(ll.to_vector(), [3,2,1,4,5,6])
        ll.insert_after(1,7)
        ll.insert_after(2,8)
        ll.insert_after(3,9)
        self.assertEqual(ll.to_vector(), [3,2,1,7,4,5,6,8,9])
        ll.remove(1)
        ll.remove(2)
        ll.remove(3)
        self.assertEqual(ll.to_vector(), [7,4,5,6,8,9])

if __name__ == '__main__':
    unittest.main()