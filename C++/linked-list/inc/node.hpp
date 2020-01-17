#ifndef NODE_H
#define NODE_H

class Node {
public:
  Node();
  Node(int);
  ~Node();
  int val;
  Node* next;
  Node* prev;
};

#endif
