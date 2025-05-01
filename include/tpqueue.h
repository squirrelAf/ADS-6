// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template<typename T>
class TPQueue {
 private:
 struct Node {
    T data;
    Node* next;
    explicit Node(T data, Node* next = nullptr) : data(data), next(next) {}
  };

  Node* front;

 public:
  TPQueue() : front(nullptr) {}

  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }

  bool isEmpty() const { return front == nullptr; }

  void push(const T& value) {
    Node* node = new Node(value);
    if (isEmpty() || front->data.prior < value.prior) {
      node->next = front;
      front = node;
    } else {
      Node* current = front;
      while (current->next && current->next->data.prior >= value.prior) {
        current = current->next;
      }
      node->next = current->next;
      current->next = node;
    }
  }

  T pop() {
    if (isEmpty()) {
      throw std::out_of_range("Queue is empty");
    }
    Node* temp = front;
    front = front->next;
    T data = temp->data;
    delete temp;
    return data;
  }

  T peek() const {
    if (isEmpty()) {
      throw std::out_of_range("Queue is empty");
    }
    return front->data;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
