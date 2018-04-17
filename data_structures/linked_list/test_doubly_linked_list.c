#include <assert.h>
#include <stdio.h>
#include "doubly_linked_list.h"

int main(){
  node_t* head = make_list_node(0);
  int arr[10] = {1,5,9,4,87,7,6,2,3,45};
  for(int i = 0; i < 10; i++){
    insert(arr[i],head);
  }

  printf("Before deleting\n");
  print_linked_list(head);
  node_t* target = head;
  while(target != NULL && target->val != 7){
    target = target->next;
  }
  delete_node(target);
  printf("\n");
  printf("After deleting\n");
  print_linked_list(head);
  return 0;
}
