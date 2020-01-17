#ifndef NODE_H
#define NODE_H

template<typename T>

class Node {
public:
  Node(T val) {
    this->val = val;
    this->prev = nullptr;
    this->next = nullptr;
  }
  ~Node() {};
  T val;
  Node* next;
  Node* prev;
};

#endif
