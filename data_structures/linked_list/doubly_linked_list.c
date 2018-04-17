#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

node_t* make_list_node(int val) {
  node_t* node = malloc(sizeof(node_t));
  node->val = val;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

node_t* insert(int val, node_t* head) {
  node_t* current_node = head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  node_t* new_node = make_list_node(val);
  current_node->next = new_node;
  new_node->prev = current_node;
}

void delete_node(node_t* node) {
  node_t* prev = node->prev;
  prev->next = node->next;
  free(node);
}

bool find_val(int val, node_t* head) {
  node_t* current_node = head;
  while (current_node != NULL){
    if (current_node->val == val){
      return TRUE;
    }
  }
  return FALSE;
}

void delete_linked_list(node_t* head) {
  node_t* current_node = head->next;
  while(current_node != NULL){
    if(current_node->prev != NULL){
      free(current_node->prev);
      current_node = current_node->next;
    }
  }
  free(current_node);
  return;
}

void print_linked_list(node_t* head) {
  node_t* current_node = head;
  while(current_node != NULL){
    printf("%d", current_node->val);
    printf("\n");
    current_node = current_node->next;
  }
}
