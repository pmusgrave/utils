#include <assert.h>
#include <stdio.h>
#include "doubly_linked_list.hpp"
#include "node.hpp"

int main(){
  Node *head = new Node(0);
  DoublyLinkedList list(head);
  int arr[10] = {1,5,9,4,87,7,6,2,3,45};
  for(int i = 0; i < 10; i++){
    list.insert(arr[i],head);
  }

  printf("Before deleting\n");
  list.print_linked_list(head);
  Node* target = head;
  while(target != nullptr && target->val != 7){
    target = target->next;
  }
  list.delete_node(target);
  printf("\n");
  printf("After deleting 7\n");
  list.print_linked_list(head);
  printf("\n");
  //list.delete_linked_list(&head);
  //  printf("After deleting entire list\n");
  //  list.print_linked_list(&head);

  return 0;
}
