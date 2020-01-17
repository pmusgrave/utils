#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "doubly_linked_list.hpp"
#include "node.hpp"

TEST_CASE("Creating new nodes", "[node_constructor]") {
  Node<int> *int_node = new Node<int>(0);
  REQUIRE(int_node->val == 0);
  REQUIRE(int_node->next == nullptr);
  REQUIRE(int_node->prev == nullptr);

  Node<char> *char_node = new Node<char>('0');
  REQUIRE(char_node->val == '0');
  REQUIRE(char_node->next == nullptr);
  REQUIRE(char_node->prev == nullptr);

  delete int_node;
  delete char_node;
}

TEST_CASE("Creating a new linked list", "[]") {
  DoublyLinkedList<int> *list = new DoublyLinkedList<int>;
  REQUIRE(list->head == nullptr);
  delete list;

  DoublyLinkedList<char> *char_list = new DoublyLinkedList<char>;
  REQUIRE(char_list->head == nullptr);
  delete char_list;

  // Node<char> *char_node = new Node<char>('q');
  // DoublyLinkedList<char> char_list_two(char_node);
  // REQUIRE(char_list2.head != nullptr);
  //  REQUIRE(char_list2.head->val == 'q');
}

//TEST_CASE("Inserting nodes", "[insert]") {

//}

/*int main(){
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
*/
