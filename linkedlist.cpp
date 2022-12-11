#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

class Node {
public:
  Node(int data) : data_(data), next_(nullptr) {}

  int data() const { return data_; }
  Node* next() const { return next_; }
  void set_next(Node* next) { next_ = next; }

private:
  int data_;
  Node* next_;
};

class LinkedList {
public:
  LinkedList() : head_(nullptr), tail_(nullptr) {}

  void insert_front(int data) {
    auto node = new Node(data);
    node->set_next(head_);
    head_ = node;
    if (!tail_) {
      tail_ = head_;
    }
  }

  void insert_back(int data) {
    auto node = new Node(data);
    if (!tail_) {
      head_ = tail_ = node;
    } else {
      tail_->set_next(node);
      tail_ = node;
    }
  }

  void insert_after(int target, int data) {
    auto current = head_;
    while (current && current->data() != target) {
      current = current->next();
    }
    if (!current) {
      return;
    }
    auto node = new Node(data);
    node->set_next(current->next());
    current->set_next(node);
    if (current == tail_) {
      tail_ = node;
    }
  }

  std::vector<int> to_vector() const {
    std::vector<int> result;
    auto current = head_;
    while (current) {
      result.push_back(current->data());
      current = current->next();
    }
    return result;
  }
  void remove(int data) {
  auto current = head_;
  Node* previous = nullptr;

  // Search for the node with the specified data
  while (current && current->data() != data) {
    previous = current;
    current = current->next();
  }

  // If the node was not found, do nothing
  if (!current) {
    return;
  }

  // If the node is the head of the list, update the head
  if (current == head_) {
    head_ = head_->next();
  }

  // If the node is the tail of the list, update the tail
  if (current == tail_) {
    tail_ = previous;
  }

  // Update the pointers to remove the node from the list
  if (previous) {
    previous->set_next(current->next());
  }
  delete current;
}

private:
  Node* head_;
  Node* tail_;
};

PYBIND11_MODULE(linked_list, m) {
  py::class_<Node>(m, "Node")
      .def_property_readonly("data", &Node::data)
      .def_property_readonly("next", &Node::next);

py::class_<LinkedList>(m, "LinkedList")
    .def(py::init<>())
    .def("insert_front", &LinkedList::insert_front)
    .def("insert_back", &LinkedList::insert_back)
    .def("insert_after", &LinkedList::insert_after)
    .def("remove", &LinkedList::remove)
    .def("to_vector", &LinkedList::to_vector);
}