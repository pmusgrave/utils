#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "node.hpp"
#include <iostream>
#include <stdlib.h>

template<typename T>

class DoublyLinkedList {
public:
  DoublyLinkedList(Node<T> *head) {
    this->head = head;
  };
  ~DoublyLinkedList() {
    Node<T>* current_node = this->head->next;
    while(current_node->next != nullptr){
      if(current_node->prev != nullptr){
        // printf("Current node is %d\n", current_node->val);
        // printf("Freeing %d\n", current_node->prev->val);
        // printf("Next node is %d\n", current_node->next->val);
        delete current_node->prev;
        current_node = current_node->next;
      }
    }
    //printf("Freeing %d\n", current_node->prev->val);
    delete current_node->prev;
    delete current_node;
  };
  Node<T>* head;

  void insert(T val, Node<T> *head) {
    Node<T> *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    Node<T> *new_node = new Node<T>(val);
    current_node->next = new_node;
    new_node->prev = current_node;
  }

  Node<T> *delete_node(Node<T> *node) {
    if(node->prev == nullptr && node->next != nullptr) {
      node->next->prev = nullptr;
      this->head = node->next;
      delete node;
      return this->head;
    }
    else if(node->prev == nullptr && node->next == nullptr){
      delete node;
      return nullptr;
    }
    else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      delete node;
    }
    // return head in case deleting head node;
    return this->head;
  }

  bool find_val(T val, Node<T> *root) {
    Node<T> *current_node = head;
    while (current_node != nullptr){
      if (current_node->val == val){
        return true;
      }
    }
    return false;
  }

  void print_linked_list(Node<T> *root) {
    Node<T> *current_node = head;
    while(current_node != nullptr){
      std::cout << current_node->val << std::endl;
      current_node = current_node->next;
    }
  }
};

#endif
