#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
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

  Node<char> *char_node = new Node<char>('q');
  DoublyLinkedList<char> char_list_two(char_node);
  REQUIRE(char_list_two.head != nullptr);
  REQUIRE(char_list_two.head->val == 'q');
  REQUIRE(char_list_two.head->next == nullptr);
}

TEST_CASE("Inserting nodes into list", "[]"){
  DoublyLinkedList<char> *null_initialized_list = new DoublyLinkedList<char>;
  REQUIRE(null_initialized_list->head == nullptr);
  null_initialized_list->insert('a', nullptr);
  REQUIRE(null_initialized_list->head != nullptr);
  REQUIRE(null_initialized_list->head->val == 'a');
  REQUIRE(null_initialized_list->head->prev == nullptr);
  REQUIRE(null_initialized_list->head->next == nullptr);

  null_initialized_list->insert('b',nullptr);
  REQUIRE(null_initialized_list->head != nullptr);
  REQUIRE(null_initialized_list->head->val == 'a');
  REQUIRE(null_initialized_list->head->next->val == 'b');

  Node<char> *target = null_initialized_list->head;
  REQUIRE(target->val == 'a');
  null_initialized_list->insert('c',target);
  REQUIRE(null_initialized_list->head->val == 'a');
  REQUIRE(null_initialized_list->head->next->val == 'c');
  REQUIRE(null_initialized_list->head->next->next->val == 'b');

  null_initialized_list->insert('d',nullptr);
  REQUIRE(null_initialized_list->head->val == 'a');
  REQUIRE(null_initialized_list->head->next->val == 'c');
  REQUIRE(null_initialized_list->head->next->next->val == 'b');
  REQUIRE(null_initialized_list->head->next->next->next->val == 'd');

  null_initialized_list->print_linked_list();
}

TEST_CASE("Deleting nodes", "[]") {
  DoublyLinkedList<float> *float_list = new DoublyLinkedList<float>;
  float_list->insert(0.0f);
  float_list->insert(1.1f);
  float_list->insert(2.3f);
  float_list->insert(3.14f);
  float_list->insert(7.2f);
  float_list->insert(9.3f);
  REQUIRE(float_list->head->val == 0.0f);
  Node<float> *target = float_list->head->next;
  REQUIRE(target->val == 1.1f);
  float_list->delete_node(target);
  REQUIRE(float_list->head->val == 0.0f);
  REQUIRE(float_list->head->next->val == 2.3f);
  float_list->print_linked_list();
}

TEST_CASE("Finding nodes", "[]") {
  DoublyLinkedList<double> *double_list = new DoublyLinkedList<double>;
  double_list->insert(1.2);
  double_list->insert(1.34);
  double_list->insert(1.56);
  double_list->insert(1.78);
  double_list->insert(9.10);
  double_list->insert(11.2);
  REQUIRE(double_list->find_val(1.2) == double_list->head);
  REQUIRE(double_list->find_val(1.56) == double_list->head->next->next);
  REQUIRE(double_list->find_val(3.14) == nullptr);
}
