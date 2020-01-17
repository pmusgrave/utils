#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "node.hpp"

class DoublyLinkedList {
public:
  DoublyLinkedList();
  DoublyLinkedList(Node *head);
  ~DoublyLinkedList();
  Node* head;
  Node* make_list_node(int val);
  void insert(int val, Node* head);
  void delete_node(Node* node);
  bool find_val(int val, Node* root);
  void print_linked_list(Node* root);
};

#endif
