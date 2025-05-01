// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>

struct SYM {
    char ch;
    int prior;
    
    SYM(char s, int p) : ch(s), prior(p) {}
};
struct Node {
    SYM data;
    Node* next;
    Node(const SYM& s) : data(s), next(nullptr) {}
};
class TPQueue {
private:
    Node* head;
    
public:
    TPQueue() : head(nullptr) {}
    
    ~TPQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void enqueue(const SYM& sym) {
        Node* newNode = new Node(sym);
        if (!head || sym.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior >= sym.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    SYM dequeue() {
        if (!head) {
            throw std::runtime_error("Очередь пустая");
        }
        Node* temp = head;
        head = head->next;
        SYM result = temp->data;
        delete temp;
        return result;
    }
