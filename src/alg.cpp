// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>
#endif 
struct SYM {
  char ch;
  int prior;
};
template <typename T>
class TPQueue {
 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }
  void push(const T& valu) {
    Node* newNode = new Node(valu);
    if (!hd || valu.prior > hd->data.prior) {
      newNode->next = hd;
      hd = newNode;
    } else {
      Node* current = head;
      while (current->next && current->next->data.prior >= val.prior) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }
T pop() {
  if (!hd) throw std::runtime_error("Queue is empty");
  Node* temp = hd;
  T res = temp->data;
  head = head->next;
  delete temp;
  return res;
}

  const T& front() const {
    if (!hd) throw std::runtime_error("Queue is empty");
    return hd->data;
  }
  bool isEmpty() const {
    return hd == nullptr;
  }
 private:
  struct Node {
    explicit Node(const T& valu) : data(valu), next(nullptr) {}
    T data;
    Node* next;
  };
  Node* head;
};
