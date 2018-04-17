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
  node->prev->next = node->next;
  node->next->prev = node->prev;
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
  while(current_node->next != NULL){
    if(current_node->prev != NULL){
      printf("Freeing %d\n", current_node->prev->val);
      free(current_node->prev);
      current_node = current_node->next;
    }
  }
  free(current_node->prev);
  free(current_node);
  free(head);
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
