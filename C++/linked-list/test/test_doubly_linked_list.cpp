#include <assert.h>
#include <stdio.h>
#include "doubly_linked_list.hpp"
#include "node.hpp"

int main(){
  Node<char> *head = new Node<char>('a');
  DoublyLinkedList<char> list(head);
  char arr[10] = {'u','q','b','d','f','i','e','z','n','b'};
  for(int i = 0; i < 10; i++){
    list.insert(arr[i],head);
  }

  printf("Before deleting\n");
  list.print_linked_list(head);
  Node<char> *target = head;
  while(target != nullptr && target->val != 'f'){
    target = target->next;
  }
  head = list.delete_node(target);
  printf("\n");
  printf("After deleting f\n");
  list.print_linked_list(head);
  printf("\n");
  //list.delete_linked_list(&head);
  //  printf("After deleting entire list\n");
  //  list.print_linked_list(&head);

  return 0;
}
