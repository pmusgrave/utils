#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "node.hpp"
#include <iostream>
#include <stdlib.h>

template<typename T>

class DoublyLinkedList {
public:
  Node<T>* head;
  Node<T>* tail;

  DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }
  DoublyLinkedList(T val) {
    this->head = new Node<T>(val);
    this->tail = this->head;
  }
  DoublyLinkedList(Node<T> *head) {
    this->head = head;
    this->tail = head;
  };
  ~DoublyLinkedList() {
    if(this->head == nullptr) { return; }
    Node<T> *current_node = this->head;
    while(current_node->next != nullptr){
      if(current_node->prev != nullptr){
        // printf("Current node is %d\n", current_node->val);
        // printf("Freeing %d\n", current_node->prev->val);
        // printf("Next node is %d\n", current_node->next->val);
        delete current_node->prev;
      }
      current_node = current_node->next;
    }
    //printf("Freeing %d\n", current_node->prev->val);
    if(current_node->prev != nullptr) {
      delete current_node->prev;
    }
    delete current_node;
  };

  // inserts new node with value val immediately following location
  // if location is a null pointer, insert node at *beginning* of list
  // to insert at end of list, pass in this->tail
  // to insert at beginning of list, pass in nullptr
  void insert(T val, Node<T> *location = nullptr) {
    if(location == nullptr && this->head == nullptr) {
      Node<T> *new_node = new Node<T>(val);
      this->head = new_node;
      this->tail = new_node;
    }
    else if (location == nullptr && this->head != nullptr) {
      Node<T> *current_node = this->head;
      Node<T> *new_node = new Node<T>(val);
      current_node->prev = new_node;
      new_node->next = current_node;
      this->head = new_node;
    }
    else if(location != nullptr && this->head != nullptr){
      Node<T> *new_node = new Node<T>(val);
      Node<T> *temp = location->next;
      location->next = new_node;
      new_node->prev = location;
      new_node->next = temp;
      if(temp != nullptr) {
        temp->prev = new_node;
      }
      else {
        this->tail = new_node;
      }
    }
  }

  // inserts new node with value val immediately following location
  // if location is a null pointer, insert node at *beginning* of list
  // to insert at end of list, pass in this->tail
  // to insert at beginning of list, pass in nullptr
  void insert(Node<T> *new_node, Node<T> *location = nullptr) {
    if(new_node == nullptr) { return; }
    if(location == nullptr && this->head == nullptr) {
      this->head = new_node;
    }
    else if (location == nullptr && this->head != nullptr) {
      Node<T> *current_node = this->head;
      current_node->prev = new_node;
      new_node->next = current_node;
      this->head = new_node;
    }
    else if(location != nullptr && this->head != nullptr){
      Node<T> *temp = location->next;
      location->next = new_node;
      new_node->prev = location;
      new_node->next = temp;
      if(temp != nullptr) {
        temp->prev = new_node;
      }
    }
  }

  void delete_node(Node<T> *node) {
    if(node == nullptr) { return; }
    if(node->prev == nullptr && node->next != nullptr) {
      node->next->prev = nullptr;
      this->head = node->next;
      delete node;
    }
    else if(node->prev == nullptr && node->next == nullptr){
      delete node;
      this->head = nullptr;
    }
    else {
      node->prev->next = node->next;
      if(node->next != nullptr) {
        node->next->prev = node->prev;
      }
      delete node;
    }
  }

  Node<T>* find_val(T val) {
    Node<T> *current_node = head;
    while (current_node != nullptr){
      if (current_node->val == val){
        return current_node;
      }
      else {
        current_node = current_node->next;
      }
    }
    return nullptr;
  }

  void print_linked_list() {
    Node<T> *current_node = this->head;
    while(current_node != nullptr){
      std::cout << current_node->val << std::endl;
      current_node = current_node->next;
    }
  }
};

#endif
