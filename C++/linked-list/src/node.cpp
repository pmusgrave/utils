#include "node.hpp"

Node::Node() {
  this->val = val;
  this->prev = nullptr;
  this->next = nullptr;
}
Node::Node(int val) {
  this->val = val;
  this->prev = nullptr;
  this->next = nullptr;
}

Node::~Node() {}
