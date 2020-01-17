#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.hpp"
#include "node.hpp"

DoublyLinkedList::DoublyLinkedList(){
  this->head = new Node();
}

DoublyLinkedList::DoublyLinkedList(Node *head){
  this->head = head;
}

DoublyLinkedList::~DoublyLinkedList(){
  Node* current_node = this->head->next;
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
}

void DoublyLinkedList::insert(int val, Node* head) {
  Node* current_node = head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  Node* new_node = new  Node(val);
  current_node->next = new_node;
  new_node->prev = current_node;
}

void DoublyLinkedList::delete_node(Node* node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  delete node;
}

bool DoublyLinkedList::find_val(int val, Node* head) {
  Node* current_node = head;
  while (current_node != NULL){
    if (current_node->val == val){
      return true;
    }
  }
  return false;
}

void DoublyLinkedList::print_linked_list(Node* head) {
  Node* current_node = head;
  while(current_node != NULL){
    printf("%d", current_node->val);
    printf("\n");
    current_node = current_node->next;
  }
}
